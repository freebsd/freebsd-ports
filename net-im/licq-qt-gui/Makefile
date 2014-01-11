# Created by: Jeremy Norris <ishmael272home.com>
# $FreeBSD$

PORTNAME=	qt4-gui
PORTVERSION=	1.8.0
CATEGORIES=	net-im
PKGNAMESUFFIX?=	${KDE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qt plugin for licq

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/licq/protocol_icq.so:${PORTSDIR}/${LICQ_PORT}-icq

USE_GCC=	yes
USE_XORG=	x11 xext ice xscrnsaver
USES=		cmake
USE_QT4=	qmake_build moc_build rcc_build uic_build linguist_build

OPTIONS_DEFINE=	KDE4
OPTIONS_DEFAULT=

LICQ_PORT?=	net-im/licq

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MKDE4}
KDE_SUFFIX=	-kde
USE_KDE4=	kdelibs automoc4
CMAKE_ARGS+=	-DWITH_KDE:BOOL=ON
PLIST_SUB+=	GUI_NAME=kde4
PLIST_SUB+=	WITH_KDE=""
PLIST_SUB+=	WITH_QT="@comment "
.else
USE_QT4+=	xml gui
PLIST_SUB+=	GUI_NAME=qt4
PLIST_SUB+=	WITH_KDE="@comment "
PLIST_SUB+=	WITH_QT=""
.endif

.include <bsd.port.mk>
