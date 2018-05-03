# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_http2
PORTVERSION=	1.10.20
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Early experience HTTP/2 modules for Apache httpd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		apache:2.4+ autoreconf libtool ssl
USE_GITHUB=	yes

GH_ACCOUNT=	icing
GH_PROJECT=	mod_h2

GNU_CONFIGURE=	yes

MODULENAME=	${GH_PROJECT}

CFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	200_mod_http2.conf 300_mod_proxy_http2.conf
PORTDOCS=	README README.md

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/200_mod_http2.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/200_mod_h2.conf.sample
	${INSTALL_DATA} ${WRKDIR}/300_mod_proxy_http2.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/300_mod_proxy_h2.conf.sample
	# Rename mod_http2 to mod_h2 to avoid conflict with Apache24
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_http2.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_http2.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so
	${RM} -v ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.mk>
