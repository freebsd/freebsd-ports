PORTNAME=	mimetreeparser
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser for MIME trees 
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	calendarcore libkleo mbox mime \
		ecm:build
USE_QT=		base

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
