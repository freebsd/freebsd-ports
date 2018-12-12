# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	2.4.d20180830
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		autoreconf compiler:c++11-lang libtool pathfix pkgconfig
CONFIGURE_ARGS=	--with-pic
CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ljson-c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	33c35f5

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}

post-patch:
	(cd ${WRKSRC} && ${SH} autogen.sh)

post-configure:
	@${REINPLACE_CMD} -e 's/#define PACKAGE/#define NDPI_PACKAGE/g' \
		-e 's/#define VERSION/#define NDPI_VERSION/g' \
			${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R}.0
	${RM} ${STAGEDIR}${PREFIX}/lib/libndpi.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libndpi.so.${PORTVERSION:R}.0 \
		${STAGEDIR}${PREFIX}/lib/libndpi.so

.include <bsd.port.mk>
