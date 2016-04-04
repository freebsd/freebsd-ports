# $FreeBSD$

PORTNAME=	libkfbapi
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/libkfbapi/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for accessing Facebook services

LICENSE=	LGPL20

LIB_DEPENDS=	libqjson.so:devel/qjson

USES=		cmake:outsource gettext tar:bzip2
USE_KDE4=	automoc4 kdelibs kdeprefix pimlibs
USE_LDCONFIG=	yes
USE_QT4=	gui webkit \
		qmake_build moc_build rcc_build uic_build

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
