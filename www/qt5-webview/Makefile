# $FreeBSD$

PORTNAME=	webview
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt component for displaying web content

USES=		compiler:c++11-lang gl qmake:norecursive qt-dist:5
USE_GL=		gl
USE_QT=		core declarative gui location network webchannel \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

.include <bsd.port.post.mk>
