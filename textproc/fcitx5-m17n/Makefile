PORTNAME=	fcitx5-m17n
PORTVERSION=	5.1.5
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Multilingualization support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-m17n

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libm17n.so:devel/m17n-lib

USES=		cmake gettext pkgconfig tar:zst

.include <bsd.port.mk>
