# $FreeBSD$

PORTNAME=	olive
DISTVERSION=	0.1.1
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-video-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NLE (nonlinear) video editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libOpenColorIO.so:graphics/opencolorio

USES=		qmake compiler:c++11-lang desktop-file-utils gl pkgconfig qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	olive-editor
GH_TAGNAME=	continuous
USE_QT=		core gui multimedia network opengl svg widgets buildtools_build linguisttools_build
USE_GL=		gl

CMAKE_ARGS=	-DGIT_HASH:STRING=NoGitHashVersion${DISTVERSION}

DATADIR=	${PREFIX}/share/olive-editor

.include <bsd.port.mk>
