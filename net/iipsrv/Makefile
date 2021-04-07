PORTNAME=	iipsrv
PORTVERSION=	1.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	me@skylord.ru
COMMENT=	IIP (Internet Imaging Protocol) FastCGI server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		autoreconf jpeg libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ruven
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iipsrv.fcgi \
		man/man8/iipsrv.8.gz

OPTIONS_DEFINE=	JPEG2000

JPEG2000_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
JPEG2000_CONFIGURE_ENABLE=	openjpeg

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
