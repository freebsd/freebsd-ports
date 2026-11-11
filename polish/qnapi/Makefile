PORTNAME=	qnapi
PORTVERSION=	0.3.0
CATEGORIES=	polish multimedia

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt-based multi-engine, multi-platform subtitle downloader
WWW=		https://github.com/MikoWhy91/qnapi \
		https://qnapi.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo
RUN_DEPENDS=	7zz:archivers/7-zip

USE_GITHUB=	yes
GH_ACCOUNT=	MikoWhy91

USES=		cmake pkgconfig qt:6
USE_QT=		5compat base \
		tools:build

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/libqnapi/src/config/configreader.cpp

.include <bsd.port.mk>
