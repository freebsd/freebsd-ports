# New ports collection makefile for:	trueos-base
# Date created:				01 Feb 2013
# Whom:					Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	trueos-base
PORTVERSION=	20160514
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD / TrueOS Command-Line Utilities

RUN_DEPENDS=	${LOCALBASE}/bin/pc-updatemanager:sysutils/pc-updatemanager \
		${LOCALBASE}/sbin/pc-sysinstall:sysutils/pc-sysinstall \
		${LOCALBASE}/bin/pc-su:sysutils/pcbsd-utils \
		${LOCALBASE}/share/pcbsd/scripts/functions.sh:sysutils/pcbsd-libsh \
		${LOCALBASE}/bin/lpreserver:sysutils/life-preserver \
		${LOCALBASE}/sbin/beadm:sysutils/beadm \
		${LOCALBASE}/bin/jobctl:sysutils/jobd \
		${LOCALBASE}/bin/sudo:security/sudo \
		${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/zsh:shells/zsh \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/sbin/smartd:sysutils/smartmontools \
		${LOCALBASE}/bin/screen:sysutils/screen \
		${LOCALBASE}/bin/tmux:sysutils/tmux \
		${LOCALBASE}/bin/nano:editors/nano \
		${LOCALBASE}/bin/zfs-stats:sysutils/zfs-stats \
		ataidle>=0:sysutils/ataidle \
		openntpd>=0:net/openntpd

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
