# Created by: Jeremy Norris <ishmael272home.com>
# $FreeBSD$

PORTNAME=	qt4-gui
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX?=	${KDE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Qt plugin for licq

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs
#BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

LICENSE=	GPLv2

USE_XORG=	x11 xext ice xscrnsaver
USE_CMAKE=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build linguist_build

.if defined(WITH_KDE)
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

LICQ_PORT?=	net-im/licq

pre-fetch:
.if defined(WITH_KDE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Build with KDE support"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You could define WITH_KDE if you want KDE support"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.include <bsd.port.post.mk>
