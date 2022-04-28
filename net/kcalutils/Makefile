PORTNAME=	kcalutils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

PATCH_SITES=	https://invent.kde.org/pim/kcalutils/-/commit/
PATCHFILES=	494331a28bb722b4ab4c38a2520f305b8f7ad8fa.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE utility and user interface functions for accessing calendar

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz
USE_KDE=	codecs config coreaddons i18n iconthemes kdelibs4support \
		widgetsaddons \
		ecm_build
# pim components
USE_KDE+=	calendarcore identitymanagement pimtextedit
USE_QT=		core gui widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
