# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	abakus
PORTVERSION=	0.92
PORTREVISION=	6
CATEGORIES=	math kde
MASTER_SITES=	http://purinchu.net/abakus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple KDE Calculator

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libmpfr.so:math/mpfr

USES=		bison cmake kde:4 qt:4 tar:bzip2
USE_KDE=	automoc4 kdelibs
USE_QT=		moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="${LDFLAGS}" \
		-DFLEX_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/flex

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
