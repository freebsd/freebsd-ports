PORTNAME=	acme
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/nginx/nginx-${PORTNAME}/releases/download/v${PORTVERSION}/:acme \
		https://nginx.org/download/:nginx
PKGNAMEPREFIX=	nginx-devel-
DISTFILES=	nginx-${PORTNAME}-${DISTVERSION}.tar.gz:acme \
		nginx-${NGINX_VERSION}.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	ACME module for NGINX
WWW=		https://github.com/nginx/nginx-acme

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

#FLAVORS=	default devel
#FLAVOR?=	${FLAVORS:[2]}
#default_PKGNAMEPREFIX=	nginx-
#devel_PKGNAMEPREFIX=	nginx-devel-
#default_CONFLICTS_INSTALL=	nginx-devel-${PORTNAME}
#devel_CONFLICTS_INSTALL=	nginx-${PORTNAME}

WRKSRC=		${WRKDIR}/nginx-${PORTNAME}-${PORTVERSION}

#.if ${FLAVOR} == devel
.include "${.CURDIR}/../nginx-devel/version.mk"
RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/nginx-devel
#.else
#.include "${.CURDIR}/../nginx/version.mk"
#RUN_DEPENDS=	${LOCALBASE}/sbin/nginx:www/nginx
#.endif

USES=		cargo cpe llvm:lib,noexport ssl

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
