# $FreeBSD$

PORTNAME=	mpfrc++
DISTVERSION=	3.6.2
CATEGORIES=	math devel
MASTER_SITES=	http://www.holoborodko.com/pavel/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance C++ interface for MPFR library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/mpreal.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/mpreal.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
