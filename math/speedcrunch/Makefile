# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	speedcrunch
PORTVERSION=	0.12.0
DISTVERSIONSUFFIX=	-${BB_COMMIT}
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard-oriented desktop scientific calculator

LICENSE=	GPLv2+

USES=		cmake compiler:c++11-lang qt:5

BB_ACCOUNT=	heldercorreia
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	c0fc9c68d292

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
CMAKE_SOURCE_PATH=	${WRKSRC}/src
USE_QT=		buildtools_build qmake_build core gui help sql widgets
USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} -e 's|-W[-_[:alnum:]]*|| ; s|metainfo|appdata| \
	    ; s|master|${PORTVERSION}-git-${BB_COMMIT}|' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
