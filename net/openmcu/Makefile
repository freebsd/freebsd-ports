# New ports collection makefile for:	openmcu
# Date created:		Wed Nov 22 08:57:55 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openmcu
PORTVERSION=	1.0a2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	openmcu_1.0alpha2

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

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
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/openmcu ${PREFIX}/bin

.include <bsd.port.mk>
