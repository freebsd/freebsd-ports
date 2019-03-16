# $FreeBSD$

PORTNAME=	qxmpp
PORTVERSION=	0.9.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX=	-qt5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

CONFLICTS?=	${PORTNAME}-[0-9]*

USES=		compiler:c++11-lang libtool pathfix pkgconfig qmake qt:5
USE_QT=		core gui network xml buildtools_build
PLIST_SUB=	QDNS="@comment "

QMAKE_ARGS=	QXMPP_NO_TESTS=1

USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project

PLIST_SUB+=	VERSION=${PORTVERSION} VERSION_MAJOR=${PORTVERSION:R}

pre-configure:
	${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
