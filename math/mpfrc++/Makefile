# $FreeBSD$

PORTNAME=	mpfrc++
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.6.8
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance C++ interface for MPFR library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/copying.txt

USE_GITHUB=	yes
GH_ACCOUNT=	advanpix
GH_PROJECT=	mpreal

NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${GH_PROJECT}-mpfrc-${DISTVERSION}

PLIST_FILES=	include/mpreal.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/mpreal.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
