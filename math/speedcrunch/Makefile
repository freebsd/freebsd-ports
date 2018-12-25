# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	speedcrunch
PORTVERSION=	0.12.0
PORTRVISION=	1
DISTVERSIONSUFFIX=	-${BB_COMMIT}
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	mikael.urankar@gmail.com
COMMENT=	Keyboard-oriented desktop scientific calculator

LICENSE=	GPLv2+

USES=		cmake qt:5

BB_ACCOUNT=	heldercorreia
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	7f2565d6a0ad

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
CMAKE_SOURCE_PATH=	${WRKSRC}/src
USE_QT=		buildtools_build qmake_build core gui help widgets
USE_XORG=	x11

post-patch:
# Remove custom options for compiler warnings
	@${REINPLACE_CMD} -e 's|-W[-_[:alnum:]]*||g' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
