PORTNAME=	UEFITool
DISTVERSIONPREFIX=	A
DISTVERSION=	67
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	UEFI images parser
WWW=		https://github.com/LongSoft/UEFITool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

USES=		compiler:c++11-lang gl qmake:outsource qt:${FLAVOR:S/qt//}
FLAVORS=	qt5 qt6
FLAVOR?=	qt5
qt5_PKGNAMESUFFIX=	-qt5
qt6_PKGNAMESUFFIX=	-qt6
USE_GITHUB=	yes
USE_GL=		gl
_USE_QT5=		core gui widgets buildtools:build qmake:build
_USE_QT6=		base
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}

WRKSRC_SUBDIR=	${PORTNAME}
GH_ACCOUNT=	LongSoft

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
