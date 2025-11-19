PORTNAME=	acme
DISTVERSION=	0.3.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/nginx/nginx-${PORTNAME}/releases/download/v${PORTVERSION}/:acme \
		https://freenginx.org/download/:freenginx
PKGNAMEPREFIX=	freenginx-devel-
DISTFILES=	nginx-${PORTNAME}-${DISTVERSION}.tar.gz:acme \
		freenginx-${NGINX_VERSION}.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	ACME module for freenginx
WWW=		https://github.com/nginx/nginx-acme

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

WRKSRC=		${WRKDIR}/nginx-${PORTNAME}-${PORTVERSION}

.include "${.CURDIR}/../freenginx-devel/version.mk"
RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/freenginx-devel

USES=		cargo cpe llvm:lib,noexport ssl

CPE_VENDOR=	nginx
CPE_PRODUCT=	nginx-acme

CARGO_ENV+=	NGINX_BUILD_DIR=${WRKDIR}/freenginx-${NGINX_VERSION}/objs
NGX_CONFIGURE_ARGS=	--with-compat \
			--with-cc-opt="-I ${LOCALBASE}/include" \
			--with-ld-opt="-L ${LOCALBASE}/lib" \
			--with-http_ssl_module

.include "${.CURDIR}/Makefile.crates"

PLIST_FILES=	libexec/freenginx/ngx_http_acme_module.so

pre-configure:
	( cd ${WRKDIR}/freenginx-${NGINX_VERSION} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${NGX_CONFIGURE_ARGS} )

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/freenginx/
	${INSTALL_DATA} ${WRKDIR}/target/release/libnginx_acme.so \
		${STAGEDIR}${PREFIX}/libexec/freenginx/ngx_http_acme_module.so

.include <bsd.port.mk>
