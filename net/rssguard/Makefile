# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rssguard
PORTVERSION=	4.2.1
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple (yet powerful) Qt5 feed reader

LICENSE=	GPLv3+

USES=		cmake qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core dbus declarative gui multimedia network sql \
		widgets xml
USE_GITHUB=	yes
GH_ACCOUNT=	martinrotter

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=	Use QtWebEngine module for internal web browser
WEBENGINE_USE=	QT=location,printsupport,webchannel,webengine
WEBENGINE_CMAKE_OFF=	-DUSE_WEBENGINE:BOOL=OFF

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librssguard.so

.include <bsd.port.mk>
