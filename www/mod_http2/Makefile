PORTNAME=	mod_http2
DISTVERSION=	2.0.33
CATEGORIES=	www
MASTER_SITES=	https://github.com/icing/mod_h2/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	HTTP/2 modules for Apache httpd
WWW=		https://github.com/icing/mod_h2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		apache libtool ssl pkgconfig
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-curl

MODULENAME=	mod_h2

SUB_FILES=	200_mod_http2.conf 300_mod_proxy_http2.conf
PORTDOCS=	README README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "powerpc" || ${ARCH:Marmv?} != ""
CFLAGS+=	-Wno-error=tautological-constant-out-of-range-compare
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/200_mod_http2.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/200_mod_h2.conf.sample
	${INSTALL_DATA} ${WRKDIR}/300_mod_proxy_http2.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/300_mod_proxy_h2.conf.sample
	# Rename mod_http2 to mod_h2 to avoid conflict with Apache24
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_http2.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_proxy_h2.so
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.post.mk>
