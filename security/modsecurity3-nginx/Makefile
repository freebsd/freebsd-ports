# $FreeBSD$

PORTNAME=	modsecurity3-nginx
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://nginx.org/download/
DISTFILES=	${_NGINX_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Instruction detection and prevention engine / nginx Wrapper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmodsecurity.so:security/modsecurity3

USES=		compiler:c11
USE_GITHUB=	nodefault
GH_TUPLE=	SpiderLabs:ModSecurity-nginx:v1.0.1:modsecurity3

HAS_CONFIGURE=	yes
# Most arguments should be derived from www/nginx's Makefile to be in sync
CONFIGURE_ARGS+=	--prefix=${PREFIX}/etc/nginx \
			--with-cc-opt="-I ${LOCALBASE}/include" \
			--with-ld-opt="-L ${LOCALBASE}/lib" \
			--conf-path=${PREFIX}/etc/nginx.conf \
			--sbin-path=${PREFIX}/sbin/nginx \
			--pid-path=${_NGINX_RUNDIR}/nginx.pid \
			--error-log-path=${_NGINX_ERRORLOG} \
			--user=${WWWOWN} --group=${WWWGRP} \
			--modules-path=${_MODULESDIR} \
			--with-file-aio \
			--http-client-body-temp-path=${_NGINX_TMPDIR}/client_body_temp \
			--http-fastcgi-temp-path=${_NGINX_TMPDIR}/fastcgi_temp \
			--http-proxy-temp-path=${_NGINX_TMPDIR}/proxy_temp \
			--http-scgi-temp-path=${_NGINX_TMPDIR}/scgi_temp \
			--http-uwsgi-temp-path=${_NGINX_TMPDIR}/uwsgi_temp \
			--http-log-path=${_NGINX_ACCESSLOG} \
			--with-http_v2_module \
			--with-http_addition_module \
			--with-http_auth_request_module \
			--with-http_dav_module \
			--with-http_flv_module \
			--with-http_gunzip_module \
			--with-http_gzip_static_module \
			--with-http_mp4_module \
			--with-http_random_index_module \
			--with-http_realip_module \
			--with-pcre \
			--with-http_secure_link_module \
			--with-http_slice_module \
			--with-http_ssl_module \
			--with-http_stub_status_module \
			--with-http_sub_module \
			--without-mail_imap_module \
			--without-mail_pop3_module \
			--without-mail_smtp_module \
			--with-mail_ssl_module \
			--with-stream_ssl_module \
			--with-stream_ssl_preread_module \
			--with-threads \
			--with-mail=dynamic \
			--with-stream=dynamic \
			--add-dynamic-module=${WRKSRC_modsecurity3}

ALL_TARGET=

WRKSRC=		${WRKDIR}/${_NGINX_DISTNAME}

PLIST_FILES=	${_MODULESDIR}/ngx_http_modsecurity_module.so

# These variables should be derived from www/nginx's Makefile
_MODULESDIR=		${PREFIX}/libexec/nginx
_NGINX_ACCESSLOG=	${_NGINX_LOGDIR}/access.log
_NGINX_ERRORLOG=	${_NGINX_LOGDIR}/error.log
_NGINX_LOGDIR=		${_NGINX_VARDIR}/log/nginx
_NGINX_RUNDIR=		${_NGINX_VARDIR}/run
_NGINX_TMPDIR=		${_NGINX_VARDIR}/tmp/nginx
_NGINX_VARDIR=	/var

_NGINX_PORTNAME=	nginx
_NGINX_PORTVERSION=	1.18.0
_NGINX_DISTNAME=	${_NGINX_PORTNAME}-${_NGINX_PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${_MODULESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/ngx_http_modsecurity_module.so \
		${STAGEDIR}${_MODULESDIR}

.include <bsd.port.mk>
