PORTNAME=	freenginx-acme-module
DISTVERSION=	0.4.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/nginx/nginx-acme/releases/download/v${DISTVERSION}/:acme \
		https://freenginx.org/download/:freenginx
DISTFILES=	nginx-acme-${DISTVERSION}.tar.gz:acme \
		freenginx-${NGINX_VERSION}.tar.gz:freenginx

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	ACME (RFC 8555) module for freenginx
WWW=		https://github.com/nginx/nginx-acme

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/freenginx

USES=		cargo cpe llvm:lib,noexport ssl

CPE_VENDOR=	nginx
CPE_PRODUCT=	nginx-acme

CARGO_ENV+=	NGINX_BUILD_DIR=${WRKDIR}/freenginx-${NGINX_VERSION}/objs

CONFLICTS_INSTALL=	freenginx-devel-acme

WRKSRC=		${WRKDIR}/nginx-acme-${DISTVERSION}

PLIST_FILES=	libexec/freenginx/ngx_http_acme_module.so

NGX_CONFIGURE_ARGS=	--with-compat --with-cc-opt="-I ${LOCALBASE}/include" \
			--with-ld-opt="-L ${LOCALBASE}/lib" \
			--with-http_ssl_module

.include "${.CURDIR}/../freenginx/version.mk"
.include "${.CURDIR}/Makefile.crates"

pre-configure:
	( cd ${WRKDIR}/freenginx-${NGINX_VERSION} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${NGX_CONFIGURE_ARGS} )

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/freenginx/
	${INSTALL_DATA} ${WRKDIR}/target/release/libnginx_acme.so \
		${STAGEDIR}${PREFIX}/libexec/freenginx/ngx_http_acme_module.so

.include <bsd.port.mk>
