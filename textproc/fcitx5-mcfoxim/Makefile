PORTNAME=	fcitx5-mcfoxim
DISTVERSION=	0.1.2
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	OpenVanilla Formosan languages for Fcitx5
WWW=		https://github.com/openvanilla/fcitx5-mcfoxim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	openvanilla

.include <bsd.port.mk>
