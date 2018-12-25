# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	adwaita-qt
DISTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-themes

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Adwaita theme for Qt applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}
qt4_PKGNAMESUFFIX=	4
qt5_PKGNAMESUFFIX=	5

USES=		cmake compiler:c++11-lib localbase pkgconfig
.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		corelib dbus gui \
		moc_build rcc_build uic_build qmake_build
CMAKE_ON=	USE_QT4
.  else
USES+=		qt:5
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
CMAKE_OFF=	USE_QT4
.  endif

USE_GITHUB=	yes
GH_ACCOUNT=	FedoraQt

PLIST_FILES=	${QT_PLUGINDIR}/styles/adwaita.so

.include <bsd.port.mk>
