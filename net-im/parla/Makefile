PORTNAME=	parla
DISTVERSION=	0.5.0
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

USE_GNOME=	gtk40 libadwaita

SHEBANG_FILES=	build.sh
SHEBANG_LANG=	bash
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	trufae

.include <bsd.port.mk>
