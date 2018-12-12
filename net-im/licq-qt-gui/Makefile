# Created by: Jeremy Norris <ishmael272home.com>
# $FreeBSD$

PORTNAME=	qt4-gui
PORTVERSION=	1.8.2
PORTREVISION=	12
CATEGORIES=	net-im
PKGNAMESUFFIX?=	${KDE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qt plugin for licq

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/licq/protocol_icq.so:${LICQ_PORT}-icq

USE_XORG=	x11 xext ice xscrnsaver sm
USES=		cmake qt:4
USE_QT=		qmake_build moc_build rcc_build uic_build linguisttools_build \
		corelib xml gui network dbus svg

OPTIONS_DEFINE=	HUNSPELL KDE4
OPTIONS_DEFAULT=HUNSPELL

LICQ_PORT?=	net-im/licq

HUNSPELL_LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell
HUNSPELL_CMAKE_ON=	-DHUNSPELL_INCLUDE_DIRS=${LOCALBASE}/include/hunspell \
			-DHUNSPELL_LIBRARIES=${LOCALBASE}/lib/libhunspell-1.6.so \
			-DHUNSPELL_FOUND:BOOL=ON
HUNSPELL_CMAKE_OFF=	-DHUNSPELL_FOUND:BOOL=OFF

KDE4_USES=		kde:4
KDE4_USE=		KDE=kdelibs,automoc4
KDE4_PREVENTS=		HUNSPELL
KDE4_CMAKE_ON=		-DWITH_KDE:BOOL=ON
KDE4_CMAKE_OFF=		-DWITH_KDE:BOOL=OFF
KDE4_PLIST_SUB=		GUI_NAME=kde4 WITH_KDE="" WITH_QT="@comment "
KDE4_PLIST_SUB_OFF=	GUI_NAME=qt4  WITH_KDE="@comment " WITH_QT=""

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MKDE4}
KDE_SUFFIX=	-kde
.endif

.include <bsd.port.mk>
