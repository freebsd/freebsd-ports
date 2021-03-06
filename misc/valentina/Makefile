# $FreeBSD$

PORTNAME=	valentina
DISTVERSION=	0.7.45
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sewing pattern drafting tool aiming to remake the garment industry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL.txt

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl gmake qmake qt:5
USE_QT=		buildtools_build concurrent core gui linguisttools_build network \
		opengl printsupport svg testlib_build widgets xml xmlpatterns
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	smart-pattern
GL_COMMIT=	80b6c97b3a105015b030d3ecac0d5fde7d190858

DOS2UNIX_FILES=	src/libs/vgeometry/vellipticalarc.cpp

QMAKE_ARGS=	CONFIG+="noTests" CONFIG+="noRunPath"
.if !defined(WITH_CCACHE_BUILD) || defined(NO_CCACHE)
QMAKE_ARGS+=	CONFIG+="no_ccache"
.endif

BINARY_ALIAS=	hg=/usr/bin/true

.include <bsd.port.mk>
