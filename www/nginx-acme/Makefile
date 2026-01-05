PORTNAME=	acme
PORTVERSION=	0.1.1
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	https://github.com/nginx/nginx-${PORTNAME}/releases/download/v${PORTVERSION}/:acme \
		https://nginx.org/download/:nginx
DISTFILES=	nginx-${PORTNAME}-${DISTVERSION}.tar.gz:acme \
		nginx-${NGINX_VERSION_DEFAULT}.tar.gz:nginx \
	        nginx-${NGINX_VERSION_DEVEL}.tar.gz:nginx

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	ACME module for NGINX
WWW=		https://github.com/nginx/nginx-acme

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

FLAVORS=	default devel
FLAVOR?=	default

USES=           cargo cpe llvm:lib,noexport ssl

default_PKGNAMEPREFIX=  nginx-
devel_PKGNAMEPREFIX=    nginx-devel-
PKGNAMEPREFIX=          ${${FLAVOR}_PKGNAMEPREFIX}

WRKSRC=		${WRKDIR}/nginx-${PORTNAME}-${PORTVERSION}

default_CONFLICTS_INSTALL=      nginx-devel-${PORTNAME}
devel_CONFLICTS_INSTALL=        nginx-${PORTNAME}
CONFLICTS_INSTALL=              ${${FLAVOR}_CONFLICTS_INSTALL}

.include "${.CURDIR}/../nginx/version.mk"
NGINX_VERSION_DEFAULT:= ${NGINX_VERSION}

.undef NGINX_VERSION
.include "${.CURDIR}/../nginx-devel/version.mk"
NGINX_VERSION_DEVEL:=   ${NGINX_VERSION}

.if ${FLAVOR} == devel
RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/nginx-devel
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/nginx
.endif

.if ${FLAVOR} == devel
NGINX_VERSION=  ${NGINX_VERSION_DEVEL}
.else
NGINX_VERSION=  ${NGINX_VERSION_DEFAULT}
.endif

CPE_VENDOR=	f5
CPE_PRODUCT=	nginx-acme

CARGO_ENV+=	NGINX_BUILD_DIR=${WRKDIR}/nginx-${NGINX_VERSION}/objs
NGX_CONFIGURE_ARGS=	--with-compat \
			--with-cc-opt="-I ${LOCALBASE}/include" \
			--with-ld-opt="-L ${LOCALBASE}/lib" \
			--with-http_ssl_module

.include "${.CURDIR}/Makefile.cargo"

PLIST_FILES=	libexec/nginx/ngx_http_acme_module.so

pre-configure:
	( cd ${WRKDIR}/nginx-${NGINX_VERSION} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${NGX_CONFIGURE_ARGS} )

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nginx/
	${INSTALL_DATA} ${WRKDIR}/target/release/libnginx_acme.so \
		${STAGEDIR}${PREFIX}/libexec/nginx/ngx_http_acme_module.so

.include <bsd.port.mk>
