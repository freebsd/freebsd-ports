# $FreeBSD$

PORTNAME=	fcitx-table-other
DISTVERSION=	0.2.3
CATEGORIES=	textproc
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Table-based input methods for Fcitx

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx
BUILD_DEPENDS=	bash:shells/bash

USES=		cmake gettext tar:xz
NO_ARCH=	yes
STRIP=		# ninja breaks without this: unknown target 'install/strip'

.include <bsd.port.mk>
