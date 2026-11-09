PORTNAME=	akonadi-contacts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement Contact Management in Akonadi
WWW=		https://www.kde.org/
LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	codecs colorscheme completion contacts coreaddons \
		guiaddons i18n iconthemes kio ktextaddons mime prison \
		service texttemplate textwidgets widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi grantleetheme
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
