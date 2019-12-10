# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttfautohint
PORTVERSION=	1.8.3
CATEGORIES=	print
MASTER_SITES=	SAVANNAH/freetype \
		SF/freetype/ttfautohint/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatic font hinting library

LICENSE=	FTL GPLv2+
LICENSE_COMB=	dual
LICENSE_NAME_FTL=	The FreeType Project license
LICENSE_FILE_FTL=	${WRKSRC}/FTL.TXT
LICENSE_FILE_GPLv2+ =	${WRKSRC}/GPLv2.TXT
LICENSE_PERMS_FTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	freetype2>=2.4.5:print/freetype2 \
		harfbuzz>=1.3.0:print/harfbuzz
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang gmake libtool pkgconfig

CONFIGURE_ARGS=	--with-doc=no --with-qt=no
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
