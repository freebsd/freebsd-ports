# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	automounter
PORTVERSION=	1.4.6
CATEGORIES=	sysutils
MASTER_SITES=	SF/bsdadminscripts/${PORTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Provides scripts to dynamically configure amd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
NO_BUILD=	yes
MANCOMPRESSED=	yes
PKGMESSAGE=	${WRKSRC}/../NOTES

MAN5=		${PORTNAME}.conf.5
MAN8=		${PORTNAME}.8

plist: patch
		@cd ${WRKSRC}; ./plist.sh -nodoc > ${PLIST}
		@${ECHO} "@dirrmtry etc/devd" >> ${PLIST}

do-install:
		@cd ${WRKSRC}; ./install.sh -prefix=${PREFIX}

post-install:
		@${JOT} -s- -b- 39
		@${CAT} ${PKGMESSAGE}
		@${JOT} -s- -b- 39

.include <bsd.port.mk>
