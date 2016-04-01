# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sx
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://cdn.skylable.com/source/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Skylable Sx is a reliable, fully distributed cluster solution

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfcgi.so:www/fcgi

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pkgconfig
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" --prefix="${STAGE}${PREFIX}" \
		--sysconfdir="${ETCDIR}" --mandir="${MANPREFIX}/man"

OPTIONS_DEFINE=	SXSERVER DOCS
SXSERVER_DESC=	Enable sxhttpd server
OPTIONS_DEFAULT=SXSERVER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSXSERVER}
CONFIGURE_ARGS+=--localstatedir="${STAGE}${PREFIX}/sxserver"
PLIST_SUB+=	SXSERVER=""
USE_RC_SUBR=	sxserver
SUB_FILES=	pkg-message
.else
CONFIGURE_ARGS+=--disable-sxhttpd --disable-server
PLIST_SUB+=	SXSERVER="@comment "
.endif

.include <bsd.port.mk>
