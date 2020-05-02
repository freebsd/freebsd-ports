# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	speedcrunch
PORTVERSION=	0.12.0	# XXX: should really be 0.12, change upon next update
DISTVERSIONSUFFIX=	-${BB_COMMIT}
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Keyboard-oriented desktop scientific calculator

LICENSE=	GPLv2+

BB_ACCOUNT=	heldercorreia
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	c0fc9c68d292

USES=		cmake compiler:c++11-lang qt:5 xorg
USE_QT=		buildtools_build qmake_build core gui help sql widgets
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
WRKSRC_SUBDIR=	src

post-patch:
	@${REINPLACE_CMD} -e 's|-W[-_[:alnum:]]*|| ; s|metainfo|appdata| \
	    ; s|master|${PORTVERSION:R}-git-${BB_COMMIT}|' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
