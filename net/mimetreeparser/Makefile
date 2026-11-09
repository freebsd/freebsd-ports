PORTNAME=	mimetreeparser
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser for MIME trees
WWW=		https://invent.kde.org/pim/mimetreeparser

LICENSE=	LGPL21

LIB_DEPENDS=	libgpgmepp.so:security/gpgmepp

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore colorscheme i18n kio mime service \
		kirigami-addons:run kirigami2:run \
		ecm:build
# KDE PIM
USE_KDE+=	libkleo mbox
USE_QT=		base declarative

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
