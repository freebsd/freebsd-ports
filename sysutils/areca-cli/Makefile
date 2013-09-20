# Created by: Rink Springer <rink@FreeBSD.org>
# $FreeBSD$

PORTNAME=	areca-cli
DISTVERSION=	${CLI_VER}.${CLI_REV}
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.areca.com.tw/RaidCards/AP_Drivers/FreeBSD/CLI/ \
		CRITICAL
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	v${CLI_VER}_${CLI_REV}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command Line Interface for the Areca ARC-xxxx RAID controllers

ONLY_FOR_ARCHS=	i386 amd64

PERIODICSCRIPT=	407.status-areca-raid

USE_ZIP=	yes
NO_BUILD=	yes

CLI_VER=	1.9.0
CLI_REV=	120503

SUB_FILES+=	${PERIODICSCRIPT}

WRKSRC=		${WRKDIR}/V${CLI_VER}_${CLI_REV}

NO_STAGE=	yes
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
