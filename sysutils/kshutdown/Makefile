PORTNAME=	kshutdown
DISTVERSION=	6.0
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility
WWW=		http://kshutdown.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 qt:6 zip
USE_GL=		gl opengl # GLX
USE_KDE=	colorscheme config configwidgets coreaddons crash dbusaddons \
		globalaccel i18n idletime notifications notifyconfig \
		statusnotifieritem widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

CMAKE_OFF=	KS_PURE_QT

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
