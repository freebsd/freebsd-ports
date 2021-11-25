PORTNAME=	qpwgraph
DISTVERSION=	0.0.7
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PipeWire Graph Qt GUI Interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

USES=		cmake pkgconfig qt:5
USE_QT=		core gui network widgets buildtools_build qmake_build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	rncbc
GL_COMMIT=	eb605ab1397adb2e565aa3e14f7b7d91b1047bf3

PLIST_FILES=	bin/qpwgraph

.include <bsd.port.mk>
