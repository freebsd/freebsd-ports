PORTNAME=	wcalc
PORTVERSION=	2.5
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/w-calc/Wcalc/${PORTVERSION}

MAINTAINER=	amarendra.godbole@gmail.com
COMMENT=	Natural-expression command-line calculator
WWW=		https://w-calc.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		localbase readline

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/wcalc \
		share/man/man1/wcalc.1.gz

.include <bsd.port.mk>
