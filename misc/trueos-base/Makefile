# New ports collection makefile for:	trueos-base
# Date created:				01 Feb 2013
# Whom:					Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	trueos-base
PORTVERSION=	20160413
CATEGORIES=	misc
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD / TrueOS Command-Line Utilities

RUN_DEPENDS=	${LOCALBASE}/bin/pc-updatemanager:sysutils/pcbsd-utils \
		${LOCALBASE}/share/pcbsd/scripts/functions.sh:sysutils/pcbsd-libsh \
		${LOCALBASE}/bin/lpreserver:sysutils/life-preserver \
		${LOCALBASE}/sbin/beadm:sysutils/beadm \
		${LOCALBASE}/bin/sudo:security/sudo \
		${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/zsh:shells/zsh \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/bin/smartd:sysutils/smartmontools \
		${LOCALBASE}/bin/screen:sysutils/screen \
		${LOCALBASE}/bin/tmux:sysutils/tmux \
		${LOCALBASE}/bin/nano:editors/nano \
		${LOCALBASE}/bin/mosh:net/mosh \
		${LOCALBASE}/bin/zfs-stats:sysutils/zfs-stats \
		ataidle>=0:sysutils/ataidle \
		openntpd>=0:net/openntpd

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
