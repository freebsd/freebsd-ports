# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_http2-devel
PORTVERSION=	1.8.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Early experience HTTP/2 modules for Apache httpd

LICENSE=	APACHE20

BUILD_DEPENDS=	libnghttp2>=1.2:www/libnghttp2
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USE_GITHUB=	yes
GH_ACCOUNT=	icing
GH_PROJECT=	mod_h2

USES=		autoreconf libtool ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=ext-
CONFIGURE_ENV=	CONFIG_SHELL=/bin/sh

USE_APACHE=	24
MODULENAME=	${GH_PROJECT}

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	README README.md
PLIST_FILES=	${APACHEMODDIR}/mod_h2.so \
		${APACHEMODDIR}/mod_proxy_h2.so

post-install:
	# Rename mod_http2 to mod_h2 to avoid conflict with Apache24
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_http2.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_http2.so
	${MV} ${STAGEDIR}${PREFIX}/share/doc/mod_http2 \
		${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so

.include <bsd.port.mk>
