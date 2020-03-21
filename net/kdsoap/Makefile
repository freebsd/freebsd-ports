# $FreeBSD$

PORTNAME=	kdsoap
DISTVERSION=	1.9.0
CATEGORIES=	net kde
MASTER_SITES=	https://github.com/KDAB/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based client-side and server-side SOAP component

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		core network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
