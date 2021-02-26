# Created by: Golyashov Sergey <svvord@soft-wizard.ru>
# $FreeBSD$

PORTNAME=	limereport
PORTVERSION=	1.5.35
CATEGORIES=	print

MAINTAINER=	svvord@soft-wizard.ru
COMMENT=	Multi-platform C++ report generator library written using Qt framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang dos2unix gl qt:5
USE_QT+=	buildtools_build core gui script sql xml svg quickcontrols2 \
		printsupport uitools network widgets declarative qmake_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	fralx
GH_PROJECT=	LimeReport

USE_LDCONFIG=	yes

LIB_DEPENDS+=	libpng16.so:graphics/png

OPTIONS_DEFINE=	DEBUG DOCS ZINT
OPTIONS_DEFAULT=	ZINT

DOCS_CMAKE_BOOL=	DOCS_INSTALL

ZINT_DESC=		Build with graphics/zint instead of bundled one
ZINT_CMAKE_ON=		SYSTEM_ZINT
ZINT_LIB_DEPENDS=	libQZint.so:graphics/zint
ZINT_EXTRA_PATCHES=	${FILESDIR}/extrapatch-barcode

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.include <bsd.port.mk>
