# New ports collection makefile for: areca-cli
# Date created:		16 July 2006
# Whom:			Rink Springer <rink@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	areca-cli
DISTVERSION=	${CLI_VER}.${CLI_REV}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.unnet.nl/pub/areca/RaidCards/AP_Drivers/FreeBSD/CLI/ \
		ftp://ftp.areca.com.tw/RaidCards/AP_Drivers/FreeBSD/CLI/
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	V${CLI_VER}.${CLI_REV}

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Command Line Interface for the Areca ARC-xxxx RAID controllers

ONLY_FOR_ARCHS=	i386 amd64

PERIODICSCRIPT=	407.status-areca-raid

USE_ZIP=	yes
NO_BUILD=	yes

CLI_VER=	1.72
CLI_REV=	250_70306

SUB_FILES+=	${PERIODICSCRIPT}

.include <bsd.port.pre.mk>

do-install:
.if ${ARCH} == "i386"
		${INSTALL_PROGRAM} ${WRKSRC}/${ARCH}/cli32 ${PREFIX}/sbin/areca-cli
.elif ${ARCH} == "amd64"
		${INSTALL_PROGRAM} ${WRKSRC}/x86_64/cli64 ${PREFIX}/sbin/areca-cli
.endif
		@${MKDIR} ${PREFIX}/etc/periodic/daily
		${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
