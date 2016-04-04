# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-qt
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${PORTVERSION}/ \
		http://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	IBus input method module for Qt4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ibus>=1.3.7:textproc/ibus
RUN_DEPENDS=	ibus>=1.3.7:textproc/ibus
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
	libicuuc.so:devel/icu

GH_ACCOUNT=	ibus

USE_QT4=	gui dbus moc_build qmake_build moc_build uic_build rcc_build
USES=		cmake pkgconfig
CMAKE_ARGS=	-DDOCDIR=${PREFIX}/share/doc/ibus-qt -DLIBDIR=lib
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PROJECTHOST=	ibus
WRKSRC=			${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
