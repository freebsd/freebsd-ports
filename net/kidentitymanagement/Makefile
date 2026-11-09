PORTNAME=	kidentitymanagement
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE pim identities
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	codecs config coreaddons i18n kio kirigami-addons \
		ktextaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	pimtextedit
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
