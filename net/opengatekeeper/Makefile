# New ports collection makefile for:	opengatekeeper
# Date created:		Wed Apr 5 11:00:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opengatekeeper
PORTVERSION=	0.9a3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/OpenGatekeeper/
DISTNAME=	opengate_0.9alpha3

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/opengate

NOCLEANDEPENDS=	yes

USE_NEWGCC=	yes
USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/opengate ${PREFIX}/bin

.include <bsd.port.mk>
