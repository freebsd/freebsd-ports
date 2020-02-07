# $FreeBSD$

PORTNAME=	qxmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	net-im
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		cmake compiler:c++11-lang libtool pathfix pkgconfig qt:5
USE_QT=		core gui network xml \
		buildtools_build qmake_build testlib_build

QMAKE_ARGS=	QXMPP_NO_TESTS=1

USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
