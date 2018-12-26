# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	4.99-beta
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/4.99%20Beta/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		alias cmake compiler:c++0x gettext kde:5 qt:5 zip
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons ecm globalaccel i18n idletime notifications notifyconfig widgetsaddons xmlgui
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ON=	KS_KF5
CMAKE_OFF=	KS_PURE_QT

.include <bsd.port.mk>
