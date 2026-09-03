PORTNAME=	ndpi
PORTVERSION=	6.0.d20260828
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library
WWW=		https://www.ntop.org/products/deep-packet-inspection/ndpi/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libjson-c.so:devel/json-c \
		librrd.so:databases/rrdtool

USES=		autoreconf compiler:c++11-lang cpe gmake libtool \
		localbase:ldflags pathfix pkgconfig
CPE_VENDOR=	ntop
USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	a9f34d0
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--with-local-libgcrypt \
		--with-pic
MAKE_ENV=	EXAMPLESDIR="${EXAMPLESDIR_REL}"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LIBS+=		-ljson-c

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R:R} \
		VER=${PORTVERSION:R}

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
