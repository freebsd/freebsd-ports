# New ports collection makefile for:	openh323
# Version required:	1.1alpha1
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	openh323_1.1alpha1
PKGNAME=	openh323-1.1.a1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pwlib_min_1.14.tar.gz

MAINTAINER=	roger@freebsd.org

WRKSRC=         ${WRKDIR}/openh323

USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test/obj_FreeBSD_x86_r/voxilla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/test/voxilla.1 ${PREFIX}/man/man1/voxilla.1

MAN1=		voxilla.1

.include <bsd.port.mk>
