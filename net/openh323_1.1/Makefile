# New ports collection makefile for:	openh323_1.1
# Date created:		July 25 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://130.104.229.225/gnomemeeting/downloads/
DISTFILES=	openh323_1.1.tar.gz \
		pwlib_min_1.1pl18.tar.gz

MAINTAINER=	roger@freebsd.org

WRKSRC=		${WRKDIR}/openh323

USE_NEWGCC=	yes
USE_BISON=	yes

USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin/simph323_1.1

.include <bsd.port.mk>
