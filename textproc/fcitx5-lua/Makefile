# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-lua
DISTVERSION=	5.0.5
CATEGORIES=	textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Lua support for Fcitx5

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5

USES=		compiler:c++17-lang gettext-tools cmake kde:5 lua:53 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

.include <bsd.port.mk>
