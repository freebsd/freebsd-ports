PORTNAME=	qpwgraph
DISTVERSION=	0.8.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PipeWire Graph Qt GUI Interface
WWW=		https://gitlab.freedesktop.org/rncbc/qpwgraph

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
GL_TAGNAME=	ab66e7d9e987a73ab87ca51de089c20b332da192

.include <bsd.port.mk>
