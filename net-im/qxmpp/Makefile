# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qxmpp
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	vg@FreeBSD.org
COMMENT=	QXmpp is an xmpp client library based on Qt & C++

LICENSE=	LGPL21

USES=		qmake pathfix pkgconfig libtool
USE_QT4=	gui network qtestlib xml uic_build moc_build \
		rcc_build

USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project

pre-configure:
	${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
