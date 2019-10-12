# $FreeBSD$

PORTNAME=	daggy
DISTVERSION=	1.1.3
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data Aggregation Utility: runs commands on remote hosts simultaneously

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbotan-2.so:security/botan2 \
		libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++17-lang gl pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	synacker
USE_QT=		core gui network buildtools_build
USE_GL=		gl

QMAKE_ARGS=	VERSION="${PORTVERSION}" BUILD_NUMBER="0"

PLIST_FILES=	bin/daggy

.include <bsd.port.mk>
