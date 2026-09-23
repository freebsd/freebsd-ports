PORTNAME=	parla
DISTVERSION=	0.9.2
PORTREVISION=	0
CATEGORIES=	net-im

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Native Gnome DeltaChat client
WWW=		https://github.com/trufae/parla

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
#		libwebkitgtk-6.0.so:www/webkit2-gtk@60 # not yet, crashes

RUN_DEPENDS=	deltachat-rpc-server>0:net/deltachat-rpc-server
USES=		desktop-file-utils gnome meson pkgconfig shebangfix vala:build

USE_GNOME=	gdkpixbuf gtk40 libadwaita

USE_GITHUB=	yes
GH_ACCOUNT=	trufae

MESON_ARGS=	-Dwebxdc=false

.include <bsd.port.mk>
