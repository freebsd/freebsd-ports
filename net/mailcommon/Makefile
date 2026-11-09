PORTNAME=	mailcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libraries for KDE PIM
WWW=		https://invent.kde.org/pim/mailcommon

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive codecs colorscheme completion dbusaddons \
		guiaddons i18n iconthemes itemmodels itemviews mime \
		syntaxhighlighting xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime identitymanagement \
		libkdepim mailimporter mailtransport messagelib \
		pimcommon
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base multimedia tools
USE_LDCONFIG=	yes

.include <bsd.port.mk>
