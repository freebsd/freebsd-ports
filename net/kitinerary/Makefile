PORTNAME=	kitinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

PATCH_SITES=	https://invent.kde.org/pim/kitinerary/-/commit/
PATCHFILES=	e99d101e2bd4c32566e238ce1340a93781e19eee.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data Model and Extraction System for Travel Reservation information

LICENSE=	LGPL21

LIB_DEPENDS=	libphonenumber.so:devel/libphonenumber \
		libpoppler.so:graphics/poppler \
		libZXing.so:textproc/zxing-cpp

USES=		compiler:c++11-lang cmake gettext gnome kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=	libxml2
USE_KDE=	coreaddons ecm i18n
# Pim components
USE_KDE+=	calendarcore contacts kpkpass mime
USE_QT=		core declarative gui network \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
