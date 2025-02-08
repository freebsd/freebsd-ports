PORTNAME=	mod_tls
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	https://github.com/icing/mod_tls/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	rustls based TLS for Apache httpd
WWW=		https://github.com/icing/mod_tls

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rustls-ffi>0.14.0:security/rustls-ffi
LIB_DEPENDS=	librustls.so:security/rustls-ffi

INSTALL_TARGET=	install-strip

USES=		apache libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rustls=${LOCALBASE}

MODULENAME=	mod_tls

SUB_FILES=	001-mod_tls.conf
PORTDOCS=	README README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so.0.0.0
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/001-mod_tls.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/001-mod_tls.conf.sample
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.post.mk>
