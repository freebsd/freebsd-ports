# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rssguard
PORTVERSION=	4.0.4
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple (yet powerful) Qt5 feed reader

LICENSE=	GPLv3+

USES=		qmake qt:5
USE_QT=		buildtools_build linguisttools_build \
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
WEBENGINE_QMAKE_OFF=	USE_WEBENGINE=false

post-patch:
	@${GREP} -Rl --null Q_OS_LINUX ${WRKSRC}/src | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,Q_OS_LINUX,Q_OS_UNIX,'
# Avoid potential linking errors when previous version of the port
# is installed.
	@${REINPLACE_CMD} -e '/^unix: LIBS/ { s,-L,, ; \
		s, -lrssguard,librssguard.so, ; }' \
		${WRKSRC}/src/rssguard/rssguard.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librssguard.so

.include <bsd.port.mk>

PATCH_ARGS+=	-l
