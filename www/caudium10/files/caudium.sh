#!/bin/sh
# init.d script for Caudium. Set the variables below to something fitting..
# This is only an example script.
#############

# The server directory where the 'start' script is located.
#
caudiumhome=@@PREFIX@@/caudium/server/

# Set this to something unique to be able to stop, reload and restart
# with this init script. It will override the setting in the config
# interface. '0' is typically replaced with the uid.
#
pidfile=/tmp/caudium_pid

# Set these to kill all processes owned by wwwuser on stop. Useful to
# reap CGI scripts.
#
# killallwww=yes
# wwwuser=www

umask 022

# If you want to start with another configuration directory:
#
# configdir=dirname

# Here you can add extra flags to the start script, like enabling or
# disabling threads.
# 
# flags="--without-threads"
flags="--with-threads"

### Check if that caudium is configured...
if [ ! -f @@PREFIX@@/caudium/configurations/Global_Variables ]
then
  echo "This server need some configuration...."
  echo "Please login as caudium user and go to @@PREFIX@@/caudium/server"
  echo "and type ./install to configure your server...."
  exit 0
fi

### You should not _have_ to change anything below here...

test -n "$pidfile" && flags="$flags --pid-file=$pidfile"
test -n "$configdir" && flags="$flags --config-dir=$configdir"

case $1 in
	'start')
          echo "Starting Caudium from $caudiumhome..."
	  if [ -z "$pidfile" ]; then
	    echo "Warning: No pid file set - cannot stop or reload."
	  elif [ -f "$pidfile" ]; then
	    read pid < $pidfile
	    if kill -0 $pid ; then
	      echo "Caudium is already running."
	      exit 0
	    fi
	    rm -f $pidfile
	    if [ -f "$pidfile" ]; then
	      echo Cannot remove pid file $pidfile
	      exit 1
	    fi
	  fi
	  if [ -x "$caudiumhome/start" ]; then
 	    cd $caudiumhome
	    ./start $flags 2>/dev/null
            echo "Done."
          else
            echo "I cannot find the Caudium dir '('$caudiumhome')'"
	  fi
	;;

	'reload')
	  if [ -z "$pidfile" ] ; then
	    echo "No pid file set."
	    exit 1
	  fi
	  echo "Reloading configurations..."
	  if [ -f $pidfile ] ; then
	    read pid < $pidfile
	    kill -HUP $pid || kill 1 $pid
	    exit 0
	  fi
	  echo "Caudium doesn't seem to be running."
	  ;;

	'restart')
	  if [ -z "$pidfile" ] ; then
	    echo "No pid file set."
	    exit 1
	  fi
	  echo Restarting Caudium...
	  if [ -f "$pidfile" ] ; then
	    read pid < $pidfile
	    kill -INT $pid || kill 2 $pid
	    rm "$pidfile"
	    echo Done.
	    exit 0
	  fi
	  echo "Caudium doesn't seem to be running."
	  echo Starting a new Caudium in $caudiumhome...
	  if [ -x "$caudiumhome/start" ]; then
 	    cd $caudiumhome
	    ./start $flags 2>/dev/null
          else
            echo "I cannot find the Caudium dir '('$caudiumhome')'"
	  fi
          echo "Done."
	;;

	'stop')
	   if [ -z "$pidfile" ] ; then
	     echo "No pid file set."
	     exit 1
	   fi
           echo "Stopping Caudium..."
	   if [ -f $pidfile ] ; then
	     if kill `cat $pidfile` ; then
               echo Caudium stopped.
	     fi
	     rm $pidfile
	   else
	     echo "Caudium doesn't seem to be running."
           fi
           # Get all the CGI scripts... :-)
           if [ x$killallwww = xyes ] ; then
	     echo Killing all programs running as the $wwwuser user.
             su $wwwuser -c "kill -9 -1"
           fi
	;;

	*)
          echo "Syntax: $0 [start|stop|restart|reload]"
          ;;
esac

exit 0
