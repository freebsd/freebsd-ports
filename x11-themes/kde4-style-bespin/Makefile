# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	bespin
PORTVERSION=	201303202227
PORTREVISION=	6
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://bsd.e-shell.net/local/
PKGNAMEPREFIX=	kde4-style-
DISTNAME=	cloudcity-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurable KDE4 style

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

WRKSRC=		${WRKDIR}/cloudcity

USES=		cmake:noninja kde:4 qt:4
USE_CXXSTD=	gnu++98
USE_KDE=	kdelibs automoc4 workspace
USE_QT=		corelib qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
