PORTNAME=	qpwgraph
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.7
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PipeWire Graph Qt GUI Interface
WWW=		https://gitlab.freedesktop.org/rncbc/qpwgraph \
		https://github.com/rncbc/qpwgraph

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cmake desktop-file-utils gl pkgconfig qt:6 shared-mime-info
USE_QT=		base svg tools:build
USE_GL=		gl opengl

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	rncbc

.include <bsd.port.mk>
