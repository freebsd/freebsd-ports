# $FreeBSD$

PORTNAME=	kitinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data Model and Extraction System for Travel Reservation information

LICENSE=	LGPL21

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libzxing.so:textproc/zxing-cpp

USES=		compiler:c++11-lang cmake gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm i18n
# Pim components
USE_KDE+=	calendarcore contacts kpkpass mime
USE_QT=		core declarative \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
