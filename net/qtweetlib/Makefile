# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtweetlib
PORTVERSION=	0.5
#PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C++ Qt based Twitter library

LICENSE=	LGPL21

LIB_DEPENDS=	qjson:${PORTSDIR}/devel/qjson

GH_ACCOUNT=	minimoog
GH_COMMIT=	2af0b78
GH_PROJECT=	QTweetLib
GH_TAGNAME=	${PORTVERSION}

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	gui moc_build network qmake_build rcc_build uic_build

NO_STAGE=	yes
.include <bsd.port.mk>
