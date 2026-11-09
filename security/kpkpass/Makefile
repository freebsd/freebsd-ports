PORTNAME=	kpkpass
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to deal with Apple Wallet pass files
WWW=		https://www.kde.org/

USES=		cmake gettext-tools kde:6 qt:6 shared-mime-info \
		tar:xz
# KDE Frameworks
USE_KDE=	archive \
		ecm:build
USE_QT=		base declarative

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
