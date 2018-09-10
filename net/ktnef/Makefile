# $FreeBSD$

PORTNAME=	ktnef
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE API for the handling of TNEF data

LICENSE=	LGPL21

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm i18n kdelibs4support
# pim components
USE_KDE+=	calendarcore calendarutils contacts
USE_QT=		core gui widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
