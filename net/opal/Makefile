# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.1.a1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTFILES=	openh323_1.1alpha1${EXTRACT_SUFX} \
		pwlib_min_1.14.tar.gz

MAINTAINER=	roger@freebsd.org

WRKSRC=         ${WRKDIR}/openh323

USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test/obj_${OPSYS}_${THE_MACHTYPE}_r/voxilla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/test/voxilla.1 ${PREFIX}/man/man1/voxilla.1

MAN1=		voxilla.1

.include <bsd.port.mk>
