#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

DATADIR="%%DATADIR%%"
#
I2P_HOME="${HOME}/i2p"
I2P_RC_SCRIPT=i2prouter
I2P_POSTINSTALL_SCRIPT=postinstall.sh
#
I2P_INSTALL_TARBALL=i2p.tar.bz2
I2P_UPDATE_ZIP=i2pupdate.zip

if [ -z "${HOME}" -o ! -d "${HOME}" ]; then
	echo 'ERROR: Please, set HOME environment variable to a valid value!'
	echo 'ERROR: You may LOSE data if the variable is pointed at an'
	echo 'ERROR: incorrect location!'
	exit 1
fi

case "$1" in
	restart|start|status|stop)
		echo "i2p ${1}"
		if [ -f "${I2P_HOME}/${I2P_RC_SCRIPT}" ]; then
			case "$1" in
				restart|start)
					echo 'To access i2p:'
					echo 'Point your browser at http://localhost:7657/ to access configuration'
					echo 'Point your browser proxy at http://localhost:4444/ to access i2p network'
				;;
			esac
			exec sh "${I2P_HOME}/${I2P_RC_SCRIPT}" ${1}
		else
			echo 'ERROR: i2p is not installed'
			echo 'ERROR: Please install i2p first'
			exit 2
		fi
		;;
	install)
		echo "i2p ${1}"
		if [ ! -d "${I2P_HOME}" ]; then
			rm -Rf "${I2P_HOME}"
			mkdir -p "${I2P_HOME}"
		fi
		cd "${HOME}" && \
			tar -xvjf "${DATADIR}/${I2P_INSTALL_TARBALL}" && \
			cd "${I2P_HOME}" &&  \
				exec sh "${I2P_HOME}/${I2P_POSTINSTALL_SCRIPT}"
		;;
	uninstall)
		echo "i2p ${1}"
		exec rm -Rf "${I2P_HOME}"
		;;
	update)
		echo "i2p ${1}"
		if [ ! -d "${I2P_HOME}" ]; then
			echo 'ERROR: i2p is not installed'
			echo 'ERROR: Please install i2p before trying to update it'
			exit 3
		fi
		cd "${I2P_HOME}" &&  \
			exec unzip -o "${DATADIR}/${I2P_UPDATE_ZIP}"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop | status | restart | install | uninstall | update }"
		echo ""
		exit 64
		;;
esac
