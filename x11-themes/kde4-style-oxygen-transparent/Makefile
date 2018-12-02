# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oxygen-transparent
PORTVERSION=	2014.03.10
PORTREVISION=	4
CATEGORIES=	x11-themes kde
MASTER_SITES=	LOCAL/dbn/${PORTNAME}
PKGNAMEPREFIX=	kde4-style-

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	KDE oxygen style with transparency

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs workspace automoc4
USE_QT=		corelib qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
