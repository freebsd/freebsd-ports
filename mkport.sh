#!/bin/sh
# Helper script which will create the port / distfiles
# from a checked out git repo

if [ -z "$1" ] ; then
   echo "Usage: ./mkports.sh <portstree> <distfiles>"
   exit 1
fi

if [ ! -d "${1}/Mk" ] ; then
   echo "Invalid directory: $1"
   exit 1
fi

portsdir="${1}"
if [ -z "$portsdir" -o "${portsdir}" = "/" ] ; then
  portsdir="/usr/ports"
fi

if [ -z "$2" ] ; then
  distdir="${portsdir}/distfiles"
else
  distdir="${2}"
fi

#Run the script to setup the port for the ports-tree
${portsdir}/Tools/scripts/setup_trueos-ports-src.sh ${portsdir}

#Set a couple variables for the TrueOS build cluster to know which is the "overall" port
port="ports-mgmt/trueos-ports-src" #reset this variable in case something else needs it
export bPort="ports-mgmt/trueos-ports-src"
