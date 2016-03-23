# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qxmpp
PORTVERSION=	0.9.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	vg@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		qmake pathfix pkgconfig libtool
USE_QT4=	gui network qtestlib xml uic_build moc_build \
		rcc_build
QMAKE_ARGS=	QXMPP_NO_TESTS=1

USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project

PLIST_SUB=	VERSION=${PORTVERSION} VERSION_MAJOR=${PORTVERSION:R}

pre-configure:
	${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
