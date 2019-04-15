# $FreeBSD$

PORTNAME=	olive
PORTVERSION=	g20190414
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-video-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NLE (nonlinear) video editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake compiler:c++11-lang desktop-file-utils gl qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	olive-editor
GH_TAGNAME=	continuous
USE_QT=		core gui multimedia network opengl svg widgets qmake_build buildtools_build linguisttools_build
USE_GL=		gl

.include <bsd.port.mk>
