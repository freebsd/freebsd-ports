# Created by: kmoore
# $FreeBSD$

PORTNAME=	nitrogen
PORTVERSION=	3.3.3
PORTREVISION=	6
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-windeco-
DISTNAME=	99551-${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE4 window decoration

LICENSE=	GPLv2

DEPRECATED=	Merged with the Oxygen windeco included with KDE4
EXPIRATION_DATE=	2014-07-14

USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake gettext
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-Source

.include <bsd.port.mk>
