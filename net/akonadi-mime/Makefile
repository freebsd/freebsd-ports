PORTNAME=	akonadi-mime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement basic email handling
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 shared-mime-info \
		tar:xz
# KDE Frameworks
USE_KDE=	i18n itemmodels kio mime xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
