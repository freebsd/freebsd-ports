PORTNAME=	parla
DISTVERSION=	0.8.0
PORTREVISION=	0
CATEGORIES=	net-im

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Native Gnome DeltaChat client
WWW=		https://github.com/trufae/parla

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

RUN_DEPENDS=	deltachat-rpc-server>0:net/deltachat-rpc-server
USES=		desktop-file-utils gnome meson pkgconfig shebangfix vala:build

USE_GNOME=	gdkpixbuf gtk40 libadwaita

USE_GITHUB=	yes
GH_ACCOUNT=	trufae

.include <bsd.port.mk>
