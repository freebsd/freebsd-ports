# New ports collection makefile for:	openmcu
# Date created:		Wed Nov 22 08:57:55 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openmcu
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	roger@FreeBSD.org
COMMENT=	OpenMCU hosts a conference call for H323 Video Conferencing users

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/openmcu ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/openh323/openmcu
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${PREFIX}/share/doc/openh323/openmcu

.include <bsd.port.mk>
