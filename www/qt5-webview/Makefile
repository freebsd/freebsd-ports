PORTNAME=	webview
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt component for displaying web content

USES=		compiler:c++11-lang gl perl5 qmake:norecursive qt-dist:5
USE_GL=		gl
USE_PERL5=	build
USE_QT=		core declarative gui location network webchannel \
		buildtools:build

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

.include <bsd.port.post.mk>
