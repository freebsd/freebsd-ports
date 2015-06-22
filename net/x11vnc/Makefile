# Created by: Loren M. Lang
# $FreeBSD$

PORTNAME=	x11vnc
PORTVERSION=	0.9.13
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/libvncserver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VNC server for use with real X displays

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xcb xdamage xfixes xrandr xinerama xext xtst xau xrender \
		xdmcp recordproto
# Sets LDFLAGS and adds to CONFIGURE_ENV, therefore we set LDFLAGS
LDFLAGS+=	-L${LOCALBASE}/lib
USE_OPENSSL=	yes
USES=		iconv jpeg pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README README.LibVNCServer TODO

OPTIONS_DEFINE=	NLS AVAHI DOCS
OPTIONS_DEFAULT=NLS AVAHI
NO_OPTIONS_SORT=yes
NLS_USES=	gettext
AVAHI_LIB_DEPENDS=	libavahi-common.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_OFF=	--without-avahi

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|include_HEADERS = |noinst_HEADERS = |' \
		-e 's|am__include_HEADERS_DIST|am__noinst_HEADERS_DIST|' \
		-e 's|/include/rfb|/include|' ${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
