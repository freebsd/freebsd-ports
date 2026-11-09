PORTNAME=	pimcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libraries for KDE PIM
WWW=		https://invent.kde.org/pim/pimcommon

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive codecs colorscheme config contacts coreaddons \
		i18n itemmodels jobwidgets kcmutils kio ktextaddons \
		newstuff purpose service widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadisearch imap ldap \
		libkdepim
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative tools:build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
