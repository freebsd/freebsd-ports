#!/bin/sh

JAVA=`which java`
JITSI="/usr/local/lib/jitsi"
JITSI_LIB="${JITSI}/lib"
JITSI_BUNDLES="${JITSI}/sc-bundles"

COMMAND="${JAVA} -Dfelix.config.properties=file:${JITSI_LIB}/felix.client.run.properties \
        -Djava.util.logging.config.file=${JITSI_LIB}/logging.properties \
        -Djna.library.path=${JITSI_LIB}/native \
        -classpath ${JITSI_LIB}/felix.jar:${JITSI_BUNDLES}/sc-launcher.jar:${JITSI_BUNDLES}/util.jar:${JITSI_LIB} \
        -Dnet.java.sip.communicator.SC_HOME_DIR_NAME=.jitsi \
        net.java.sip.communicator.launcher.SIPCommunicator"

export LD_LIBRARY_PATH="${LD_LIBRARY_PATH:+$LD_LIBRARY_PATH:}${JITSI_LIB}/native"

cd ${JITSI}
exec ${COMMAND} $*
