# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
DISTVERSION=	0.5.0-beta2
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	citrin@citrin.ru
COMMENT=	Text-based utility for work with dictionaries in StarDict's format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource pkgconfig readline tar:bzip2
USE_GNOME=	glib20

SUB_FILES=	pkg-message

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
