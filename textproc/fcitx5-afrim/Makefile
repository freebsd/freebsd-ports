PORTNAME=	fcitx5-afrim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	textproc

MAINTAINER=	brady.fomegne@outlook.com
COMMENT=	AFRIM support for Fcitx5
WWW=		https://fodydev.github.io/afrim-man/ \
		https://github.com/fodydev/fcitx5-afrim

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cbindgen:devel/rust-cbindgen \
		corrosion>=0:devel/corrosion
LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5

USES=		cargo cmake kde:6 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fodydev

USE_KDE=	ecm

PLIST_FILES=	lib/fcitx5/libafrim.so \
		share/fcitx5/addon/afrim.conf \
		share/fcitx5/inputmethod/afrim.conf

CARGO_SRC_SUBDIR=	afrim

.include <bsd.port.mk>
