# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rssguard
PORTVERSION=	3.9.2
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple (yet powerful) Qt5 feed reader

LICENSE=	GPLv3+

USES=		qmake qt:5
USE_QT=		buildtools_build linguisttools_build \
		core declarative gui network sql widgets xml
USE_GITHUB=	yes
GH_ACCOUNT=	martinrotter

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT=	WEBENGINE

WEBENGINE_DESC=	Use QtWebEngine module for internal web browser
WEBENGINE_USE=	QT=location,printsupport,webchannel,webengine
WEBENGINE_QMAKE_OFF=	USE_WEBENGINE=false

post-patch:
# Remove unused #include <QtConcurrent/QtConcurrentRun> to avoid needless
# USE_QT+=concurrent_build dependency
	${REINPLACE_CMD} -e '/QtConcurrent/d' \
		${WRKSRC}/src/librssguard/miscellaneous/feedreader.cpp \
		${WRKSRC}/src/librssguard/services/gmail/gui/formaddeditemail.cpp
# Drop executable bits to prevent bogus stripping attempts
	cd ${WRKSRC}/src/librssguard/services/abstract && ${CHMOD} -x \
		gui/authenticationdetails.h importantnode.h label.h \
		labelsnode.h
	${CHMOD} -x ${WRKSRC}/resources/graphics/rssguard.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librssguard.so

.include <bsd.port.mk>
