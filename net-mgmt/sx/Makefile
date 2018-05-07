# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sx
PORTVERSION=	2.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://cdn.skylable.com/source/

MAINTAINER=	neel@neelc.org
COMMENT=	Skylable Sx is a reliable, fully distributed cluster solution

LICENSE=	GPLv2

DEPRECATED=	Upstream gone, does not fetch
EXPIRATION_DATE=2018-07-07

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfcgi.so:www/fcgi \
		libyajl.so:devel/yajl \
		libltdl.so:devel/libltdl

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USES=		fuse gmake libtool pkgconfig sqlite
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" --prefix="${PREFIX}" \
		--sysconfdir="${ETCDIR}" --mandir="${MANPREFIX}/man" \
		--with-system-libs

OPTIONS_DEFINE=	SXSERVER DOCS
SXSERVER_DESC=	Enable sxhttpd server
OPTIONS_DEFAULT=SXSERVER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSXSERVER}
CONFIGURE_ARGS+=--localstatedir="${PREFIX}/sxserver"
PLIST_SUB+=	SXSERVER=""
USE_RC_SUBR=	sxserver
SUB_FILES=	pkg-message
.else
CONFIGURE_ARGS+=--disable-sxhttpd --disable-server
PLIST_SUB+=	SXSERVER="@comment "
.endif

.if ${OPSYS} == FreeBSD
PLIST_FILES+=	lib/sxclient/libsxf_aes256-20.so \
		lib/sxclient/libsxf_aes256.so \
		lib/sxclient/libsxf_aes256_dummy-00.so \
		lib/sxclient/libsxf_aes256_dummy.so
.endif

.include <bsd.port.mk>
