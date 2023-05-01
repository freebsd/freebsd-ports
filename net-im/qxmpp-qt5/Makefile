PORTNAME=	qxmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	net-im

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XMPP client library based on Qt and C++
WWW=		https://github.com/qxmpp-project/qxmpp/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libomemo-c.so:security/libomemo-c

USES=		cmake compiler:c++17-lang libtool pathfix pkgconfig qca qt:5
USE_QT=		core gui network xml \
		buildtools:build qmake:build testlib:build
CMAKE_ARGS=	-DQT_VERSION_MAJOR=5
CMAKE_ON=	BUILD_OMEMO

USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
