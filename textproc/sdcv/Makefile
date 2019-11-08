# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
PORTVERSION=	0.5.2
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	citrin@citrin.ru
COMMENT=	Text-based utility for work with dictionaries in StarDict's format #'

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gnome pkgconfig readline
USE_GNOME=	glib20

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	Dushistov

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=OFF

post-patch:
.for i in doc/sdcv.1 src/sdcv.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor

post-build-NLS-on:
	cd ${BUILD_WRKSRC} && ${MAKE_CMD} lang

.include <bsd.port.mk>
