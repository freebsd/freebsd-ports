# Created by: mfechner@FreeBSD.org
# $FreeBSD$

PORTNAME=	knxd
PORTVERSION=	0.14.33
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Advanced router/gateway for KNX

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libev.so:devel/libev \
		libfmt.so:devel/libfmt

USES=		autoreconf compiler:c11 gmake libtool pkgconfig
USE_RC_SUBR=	knxd
USE_GITHUB=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
GH_ACCOUNT=	knxd
GH_PROJECT=	knxd
GH_TAGNAME=	7a3c5e065e5ab26eeb14257c8dff05fa94e9373e
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-systemd --disable-usb \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-I${LOCALBASE}/include -L/${LOCALBASE}/lib"

.include <bsd.port.mk>
