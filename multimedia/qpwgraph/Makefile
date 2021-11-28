PORTNAME=	qpwgraph
DISTVERSION=	0.0.9
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
GL_COMMIT=	71edb283e7b5d4429d5ef9951de6b740afb07790

PLIST_FILES=	bin/qpwgraph

.include <bsd.port.mk>
