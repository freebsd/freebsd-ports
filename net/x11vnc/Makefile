# Created by: Loren M. Lang
# $FreeBSD$

PORTNAME=	x11vnc
PORTVERSION=	0.9.13
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/libvncserver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VNC server for use with real X displays

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpthread-stubs.so:devel/libpthread-stubs

USE_XORG=	x11 xcb xdamage xfixes xrandr xinerama xext xtst xau xrender \
		xdmcp recordproto
# Sets LDFLAGS and adds to CONFIGURE_ENV, therefore we set LDFLAGS
LDFLAGS+=	-L${LOCALBASE}/lib
USE_OPENSSL=	yes
USES=		iconv pkgconfig jpeg
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README README.LibVNCServer TODO

OPTIONS_DEFINE=	NLS AVAHI DOCS
OPTIONS_DEFAULT=AVAHI
NO_OPTIONS_SORT=yes
NLS_USES=	gettext
AVAHI_LIB_DEPENDS=	libavahi-common.so:net/avahi-app
AVAHI_CONFIGURE_OFF=	--without-avahi

post-patch:
	${REINPLACE_CMD} -e 's|include_HEADERS = |noinst_HEADERS = |' \
		-e 's|am__include_HEADERS_DIST|am__noinst_HEADERS_DIST|' \
		-e 's|/include/rfb|/include|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
