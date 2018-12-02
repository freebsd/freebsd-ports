# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polyester
PORTVERSION=	2.0.0
PORTREVISION=	11
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.notmart.org/files/
PKGNAMEPREFIX=	kde4-style-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE style and window decoration

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
