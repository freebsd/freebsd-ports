# $FreeBSD$

PORTNAME=	kcalutils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE utility and user interface functions for accessing calendar

LICENSE=	LGPL21

USES=		cmake:outsource compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz
USE_KDE=	codecs config coreaddons ecm i18n iconthemes kdelibs4support \
		widgetsaddons
# pim components
USE_KDE+=	calendarcore identitymanagement pimtextedit
USE_QT=		core gui widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
