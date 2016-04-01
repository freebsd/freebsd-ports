# Created by: Naoki Tsurutani
# $FreeBSD$

DISTFILES:=	install_flash_player_11_linux.i386.tar.gz:plugin
USE_LINUX=		f10
ALSA_RUN_DEPENDS=	linux-${USE_LINUX}-alsa-lib>=1.0.21_5:audio/linux-f10-alsa-lib
USE_LINUX_APPS=		curl cyrus-sasl2 gtk2 libssh2 nspr nss openldap
MASTERDIR=		${.CURDIR}/../linux-c6-flashplugin11
LINUX_RPM_ARCH=		i686

.include "${MASTERDIR}/Makefile"
