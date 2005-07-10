#!/bin/sh
#******************************************************************************
#DESCRIPTION
#
#   Queue displayer/manager for AntiVir Milter.
#
#VERSION 1.2
#
#USAGE
#    avq [--conf=.conf] "
#    avq [--queue=DIR] "
#    avq [--remove=ID]... "
#    avq [--deliver=ID|--reprocess=ID]... "
#    avq [--delivery|--check|--enqueue=CTRL-FILE]... "
#
#    "--deliver= and --delivery make the message go to the Q state."
#    "--reprocess= and --check    make the message go to the q state."
#    "--deliver= and --reprocess= work on messages already in the queue."
#    "--delivery and --check      apply to messages being enqueued."
#    "ID is like '32557-0BE692EB'."
#    "CTRL-FILE is like '/path/to/a/queue/?f-32557-0BE692EB'."
#
#LEGAL
#   Copyright (c) 2001 - 2004 H+BEDV Datentechnik GmbH
#
#   This script is free software; you can redistribute it and/or
#   modify it under the terms of the GNU  General Public
#   License as published by the Free Software Foundation; either
#   version 2 of the License, or (at your option) any later version.
#
#   This script is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   General Public License for more details.
#
#   You should have received a copy of the GNU General Public
#   License along with this library; see the file COPYING.LIB.
#   If not, write to the Free Software Foundation,
#   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#******************************************************************************

configuration=/etc/avmilter.conf

for arg ;
do
 case ${arg} in
  --conf=*)
  configuration=`echo "${arg}" | sed -e 's/--conf=//'`
  ;;
  esac
done

if [ ! -e ${configuration} ]
then
 echo "The configuration file (${configuration}) does not exist"
 echo "Please re-run the script"
 echo "with the option --conf=/path/to/.conf"
 exit
fi

queue="`egrep -i '^[Ss][Pp][Oo][Oo][Ll][Dd][Ii][Rr]' ${configuration} | awk '{print $2;}'`"
queue_set=0
pname="`basename $0`"
pblan="`echo ${pname} | sed -e 's/./ /g'`"
newstate=q
ctrl=
data=
systeme="`uname`"
date_param="-d"

usage() {
    echo "${pname} usage:"
    echo "    ${pname} [--conf=.conf] "
    echo "    ${pname} [--queue=DIR] "
    echo "    ${pblan} [--remove=ID]... "
    echo "    ${pblan} [--deliver=ID|--reprocess=ID]... "
    echo "    ${pblan} [--delivery|--check|--enqueue=CTRL-FILE]... "
    echo ""
    echo "--deliver=   and --delivery make the message go to the Q state."
    echo "--reprocess= and --check    make the message go to the q state."
    echo "--deliver= and --reprocess= work on messages already in the queue."
    echo "--delivery and --check      apply to messages being enqueued."
    echo "ID is like '32557-0BE692EB'."
    echo "CTRL-FILE is like '/path/to/a/queue/?f-32557-0BE692EB'."
}


#  df- data file.
#  xf- ctrl file transient.
#  qf- ctrl file queued for virus check.
#  Qf- ctrl file queued for direct delivery.
#  vf- ctrl file virus detected.
#  mf- ctrl file mime problem detected (pathological email).


if [ -z ${queue} ] ; then
    queue="/var/spool/avmilter" 
fi

case "$systeme" in 

FreeBSD)
    date_param="-r"
    ;;
esac

for arg ; do
    case "$arg" in
    --conf=*)
    ;;

    --queue=*)
        if [ $queue_set -ne 0 ] ; then
            echo "${pname}: queue already set to '${queue}'."
            exit 2            
        fi
        queue_set=1
        queue=`echo "$arg"|sed -e 's/--queue=//'`
        if [ ! -d "$queue" ] ; then
            echo "${pname}: there is no directory named '$queue'."
            exit 2
        fi
        ;;

    --deliver=*|--reprocess=*|--remove=*|--hold=*)
        case "$arg" in
        --reprocess=*)
            id=`echo "$arg"|sed -e 's/--reprocess=//'`
            newstate=q
            action=reprocessing
            ;;
        --deliver=*)
            id=`echo "$arg"|sed -e 's/--deliver=//'`
            newstate=Q
            action=delivery
            ;;
        --remove=*)
            id=`echo "$arg"|sed -e 's/--remove=//'`
            newstate=R
            action=removing
            ;;
        --hold=*)
            id=`echo "$arg"|sed -e 's/--hold=//'`
            newstate=H
            action=holding
            ;;
        esac
        ctrl=`/bin/ls "${queue}"/*/[HQqvmx]f-"${id}"`
        data=`/bin/ls "${queue}"/*/[Dd]f-"${id}"`
       echo "ctor: ${ctrl} ${data}" 
        if [ ! -f "${data}" ] ; then
            echo "${pname}: there is no data  file id '${id}'"\
                 "in queue '$queue'."
            exit 3            
        fi
        if [ ! -f "${ctrl}" ] ; then
            echo "${pname}: there is no control file id '${id}'"\
                 "in queue '$queue'."
            exit 3            
        fi
        bnam="`basename ${ctrl}`"
        case $newstate in
        R)
            ( /bin/rm "${ctrl}" && /bin/rm "${data}" ) \
            && echo "${pname}: message id '${id}' removed." \
            || echo "${pname}: could not remove message id '${id}'."
            ;;
        *)
            Qtrl="`echo $bnam|sed -e 's/^.\(.*\)$/'${newstate}'\1/'`"
            
            nctrl="${queue}/incoming/${Qtrl}"
            ndata="${queue}/incoming/`basename ${data}`"

            if [ "${ctrl}" = "${nctrl}" ] ; then
                echo "${pname}: ${action} of message"\
                     "id '${id}' already forced." 
            else
                [ "${data}" = "${ndata}" ] || mv "${data}" "${ndata}"
                mv "${ctrl}" "${nctrl}" \
                && echo "${pname}: ${action} of message id"\
                        "'${id}' will be forced."\
                || echo "${pname}: failed forcing ${action}"\
                        "of message id '${id}'."
            fi
            ;;
        esac
        ;;

    --delivery)
        newstate=Q
        ;;
    --check)
        newstate=q
        ;;
    --enqueue=*)
        ctrl=`echo "$arg"|sed -e 's/--enqueue=//'`
        if [ -f "${ctrl}" ] ; then
            ddir="`dirname $ctrl`"
            bnam="`basename $ctrl`"
            data="$ddir/`echo $bnam|sed -e 's/.\(.*\)/d\1/'`"
            nnam="`echo $bnam|sed -e 's/^.\(.*\)$/'${newstate}'\1/'`"
            id="`echo $bnam|sed -e 's/^..-\(.*\)$/\1/'`"
            user=`egrep -i '^user' "$configuration"|awk '{print $2;}'`
            group=`egrep -i '^group' "$configuration"|awk '{print $2;}'`
            if [ -f "${data}" ] ; then
                if /bin/ls "${queue}"/*/??-"${id}" > /dev/null 2>&1 ; then
                    echo "${pname}: there is already files with id '${id}'"
                    echo "${pblan}  in queue '${queue}'."
                    exit 3
                else
                    cp "${data}" "${queue}/incoming/" \
                    && cp "${ctrl}" "${queue}/incoming/${nnam}" \
                    && chown ${user}.${group} "${queue}/incoming/"??"-${id}" \
                    && echo "${pname} enqueued '${nnam}'."
                fi
            else
                echo "${pname}: there is no data file named '${data}'."
                exit 3
            fi
        else
            echo "${pname}: there is no control file named '${ctrl}'."
            exit 3
        fi
        ;;

    -h|--help)
        usage
        exit 0
        ;;
    -*)
        echo "${pname}: unknown option '${arg}'."
        usage
        exit 1
        ;;
    *)
        echo "${pname}: superfluous argument '${arg}'."
        usage
        exit 1
        ;;
    esac
done

if [ -z ${queue} ] ; then
    queue="/var/spool/avmilter" 
fi

cd "${queue}"
qsize=` ( ( cd incoming ; /bin/ls -1 ) ; ( cd rejected ; /bin/ls -1 ) ; ( cd outgoing ; /bin/ls -1 ) ) | /usr/bin/wc -l`

if [ $qsize -eq 0 ] ; then
    echo "AntiVir Milter mail queue is empty."
    exit 0
fi
printf "\n%c %14s %8s %19s %s\n" \
    S "---Queue ID---" "--Size--" \
    "----Arrival Time---" "---Sender/Recipients-------"

    find . -type f -mindepth 2 -maxdepth 2 -iname "??-*-*" | cut -d / -f 2- | xargs ls -l \
    | awk '{ if(($9!="")&&($9!="./")&&($9!="../")){print $9 " " $5} }' \
    | awk '
BEGIN{
    nid=0;
}
{
    dir_file=$1;
    size=$2;
    

    dir=substr(dir_file,1,9);
    if((dir=="incoming/")||(dir=="rejected/")||(dir=="outgoing/")){
        file=substr(dir_file,10,length(dir_file));
    }else{
        file=dir_file;
    }
    state=substr(file,1,1);
    id=substr(file,4,length(file));
    
    if(!id_exist(id)){
        ids[nid++]=id;
    }
    if(state=="d"){
        sizes[id]=size;
    }else{
        states[id]=state;
    }
    whereis[id]=dir; 
}

function id_exist(id){
    for(i=0;i<nid;i++){
        if(ids[i]==id){
            return(1);
        }
    }
    return(0);
}

END{
    for(i=0;i<nid;i++){
        id=ids[i];
        state=states[id];
        if(state==""){
            state="E";
        }
        size=sizes[id];
        where=whereis[id];
        printf "%c %16s %10d %s\n",state,id,size,where;
    }
}
' \
| sort -t- +0.0 -0.1 +0.2n +1 \
| while read state id size where; do

    from=`grep -s FROM "${queue}/${where}${state}f-${id}"|awk '{print $2}'`
    ctim=`grep -s CTIM "${queue}/${where}${state}f-${id}"|awk '{print $2}'`
    rcpt=`grep -s RCPT "${queue}/${where}${state}f-${id}"|awk '{printf "%46s%s\n","",$2;}'`
    stat=`grep -s STAT "${queue}/${where}${state}f-${id}"\
            |awk 'BEGIN{s="Not processed yet.";r="";}\
            {if($2==2){s="MIME problem.";}else if($2==3){s="Found";}else 
             if($2==1){s="OK.";}r=substr($0,8);}END{printf "%-14s%s",s,r;}'`
case "$systeme" in 
FreeBSD | OpenBSD)
    mailtime=`date $date_param "$ctim" +"%Y-%m-%d %T"` 
    ;;
*)
    mailtime=`date $date_param "1970-01-01 $ctim sec" +"%Y-%m-%d %T"` 
    ;;
esac    
#    mailtime=`date $date_param "1970-01-01 $ctim sec" +"%Y-%m-%d %T"` 
    printf "%c %14s %8d %s %s\n%s\n        --> %s\n\n" \
    "$state" "$id" "$size" "$mailtime" "$from" "$rcpt" "$stat" 
done

exit 0
#END

