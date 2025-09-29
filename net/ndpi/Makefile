PORTNAME=	ndpi
PORTVERSION=	4.14.d20250609
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library
WWW=		https://www.ntop.org/products/deep-packet-inspection/ndpi/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librrd.so:databases/rrdtool \
		libjson-c.so:devel/json-c \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		autoreconf compiler:c++11-lang cpe libtool localbase:ldflags pathfix \
		pkgconfig
CPE_VENDOR=	ntop
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-pic --with-local-libgcrypt
CPPFLAGS=	-I${LOCALBASE}/include/json-c
LIBS=		-ljson-c
MAKE_ENV=	EXAMPLESDIR="${EXAMPLESDIR_REL}"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	f2a9087

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R:R} VER=${PORTVERSION:R}

post-configure:
	@${REINPLACE_CMD} -e 's/#define PACKAGE/#define NDPI_PACKAGE/g' \
		-e 's/#define VERSION/#define NDPI_VERSION/g' \
			${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R}.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ndpiReader
	${RM} ${STAGEDIR}${PREFIX}/lib/libndpi.so \
		${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R:R}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R}.0 \
		${STAGEDIR}${PREFIX}/lib/libndpi.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R}.0 \
		${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
