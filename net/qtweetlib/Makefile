# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtweetlib
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C++ Qt based Twitter library

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4

GH_ACCOUNT=	minimoog
GH_PROJECT=	QTweetLib

USES=		cmake qt:4
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		gui moc_build network qmake_build rcc_build uic_build

.include <bsd.port.mk>
