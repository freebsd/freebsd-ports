PORTNAME=	libkgapi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE based library to access google services
WWW=		https://progdan.cz/category/akonadi-google/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore contacts wallet \
		ecm:build
USE_QT=		base tools:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
