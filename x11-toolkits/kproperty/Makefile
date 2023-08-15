PORTNAME=		kproperty
DISTVERSION=		3.2.0
PORTREVISION=	2
CATEGORIES=		x11-toolkits kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Property editing framwork
WWW=		https://www.kexi-project.org/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons guiaddons i18n widgetsaddons \
		ecm:build
USE_QT=		core declarative gui widgets xml \
		buildtools:build qmake:build

CONFLICTS_INSTALL=	calligra-2*

.include <bsd.port.mk>
