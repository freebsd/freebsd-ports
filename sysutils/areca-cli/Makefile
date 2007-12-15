# New ports collection makefile for: areca-cli
# Date created:		16 July 2006
# Whom:			Rink Springer <rink@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	areca-cli
PORTVERSION=	${CLI_VER}.${CLI_REV}
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.unnet.nl/pub/areca/RaidCards/AP_Drivers/FreeBSD/CLI/ \
		ftp://ftp.areca.com.tw/RaidCards/AP_Drivers/FreeBSD/CLI/
DISTNAME=	V${CLI_VER}_${CLI_REV}

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Command Line Interface for the Areca ARC-xxxx RAID controllers

ONLY_FOR_ARCHS=	i386 amd64

PERIODICSCRIPT=	407.status-areca-raid

USE_ZIP=	yes
NO_BUILD=	yes

CLI_VER=	1.5
CLI_REV=	50930

SUB_FILES+=	${PERIODICSCRIPT}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/cli32 ${PREFIX}/sbin/areca-cli
		@${MKDIR} ${PREFIX}/etc/periodic/daily
		${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
