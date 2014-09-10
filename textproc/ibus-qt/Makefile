# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-qt
PORTVERSION=	1.3.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	IBus input method module for Qt4

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ibus-1.0.pc:${PORTSDIR}/textproc/ibus \
	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
	${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu \
	doxygen:${PORTSDIR}/devel/doxygen
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ibus-1.0.pc:${PORTSDIR}/textproc/ibus \
	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
	${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu

USE_QT4=	gui dbus moc_build qmake_build moc_build uic_build rcc_build
USES=		cmake pkgconfig
CMAKE_ARGS=	-DDOCDIR=${PREFIX}/share/doc/ibus-qt -DLIBDIR=lib
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PROJECTHOST=	ibus
WRKSRC=			${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
