# $FreeBSD$

PORTNAME=	apcups
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	plasma-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plasma applet to monitor the status of APC UPS

BROKEN=		Unfetchable (google code has gone away)

PROJECTHOST=	plasma-apcups

USES=		cmake gettext kde:4
USE_KDE=	automoc4 kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
