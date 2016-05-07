# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	abakus
PORTVERSION=	0.92
PORTREVISION=	3
CATEGORIES=	math kde
MASTER_SITES=	http://purinchu.net/abakus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple KDE Calculator

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libmpfr.so:math/mpfr

USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		bison cmake tar:bzip2
CMAKE_ARGS=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="${LDFLAGS}" \
		-DFLEX_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/flex

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
