PORTNAME=	iipsrv
DISTVERSION=	1.2
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	me@skylord.ru
COMMENT=	IIP (Internet Imaging Protocol) FastCGI server
WWW=		https://iipimage.sourceforge.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		autoreconf jpeg libtool pkgconfig localbase
USE_GITHUB=	yes
GH_ACCOUNT=	ruven
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/iipsrv.fcgi \
		share/man/man8/iipsrv.8.gz

OPTIONS_DEFINE=	JPEG2000 PNG WEBP

JPEG2000_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
JPEG2000_CONFIGURE_ENABLE=	openjpeg

PNG_LIB_DEPENDS=		libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png

WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	webp

post-patch:
	@${REINPLACE_CMD} -e 's|noinst_PROGRAMS|bin_PROGRAMS|g' \
		${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|include_HEADERS|noinst_HEADERS|g' \
		${WRKSRC}/fcgi/Makefile.am
	@${REINPLACE_CMD} -e 's|include_HEADERS|noinst_HEADERS|g' \
		${WRKSRC}/fcgi/include/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

.include <bsd.port.mk>
