#! /bin/sh
#
# $FreeBSD$

set -e

warning() {
    echo "Kept %%PREFIX%%/etc/%%APP_NAME%%/resin.xml intact from previous installation, please diff"
    echo "against %%PREFIX%%/etc/%%APP_NAME%%/resin.xml-dist for merging changes"
}

# Install config file only if none is already there
if test -e %%PREFIX%%/etc/%%APP_NAME%%/resin.xml && \
    ! cmp -s %%WRKDIR%%/resin.conf %%PREFIX%%/etc/%%APP_NAME%%/resin.xml ; then
        echo
        echo "********************************************************************************"
        warning | fmt -w 80
        echo "********************************************************************************"
        echo
else
    test -d %%PREFIX%%/etc/%%APP_NAME%% || mkdir %%PREFIX%%/etc/%%APP_NAME%%
    echo Created configuration directory %%PREFIX%%/etc/%%APP_NAME%%
    cp %%WRKDIR%%/resin.conf %%PREFIX%%/etc/%%APP_NAME%%/resin.xml
    echo Installed %%PREFIX%%/etc/%%APP_NAME%%/resin.xml
fi

# Install new config file with '-dist' appended
cp %%WRKDIR%%/resin.conf %%PREFIX%%/etc/%%APP_NAME%%/resin.xml-dist
echo Installed %%PREFIX%%/etc/%%APP_NAME%%/resin.xml-dist

cp %%WRKSRC%%/conf/app-default.xml %%PREFIX%%/etc/%%APP_NAME%%
echo Installed %%PREFIX%%/etc/%%APP_NAME%%/app-default.xml

install %%WRKDIR%%/resin.sh.in %%PREFIX%%/etc/rc.d/%%APP_NAME%%.sh
chmod 755 %%PREFIX%%/etc/rc.d/%%APP_NAME%%.sh
echo Installed %%PREFIX%%/etc/rc.d/%%APP_NAME%%.sh

install %%WRKDIR%%/resinctl %%PREFIX%%/sbin/%%APP_NAME%%ctl
echo Installed %%PREFIX%%/sbin/%%APP_NAME%%ctl

test -d %%APP_HOME%% || mkdir %%APP_HOME%%
echo Created installation directory %%APP_HOME%%

list()
{
    for dir in %%COPYDIRS%% ; do
        ( cd %%WRKSRC%% ; find $dir )
    done
}

# Remove all empty dirs
( cd %%WRKSRC%% && find %%COPYDIRS%% -type d -empty -delete )

echo Installing in %%APP_HOME%%
list | ( cd %%WRKSRC%% && cpio -pdm -L -R $RUNASUSER:$GROUP %%APP_HOME%% )
