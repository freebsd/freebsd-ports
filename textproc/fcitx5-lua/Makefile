PORTNAME=	fcitx5-lua
DISTVERSION=	5.0.15
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Lua support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-lua

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5

USES=		cmake compiler:c++17-lang gettext-tools kde:5 lua:53 pkgconfig \
		tar:zst

USE_KDE=	ecm

.include <bsd.port.mk>
