# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kgpg
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	security kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Encryption tool for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

RUN_DEPENDS=	gpg2:security/gnupg

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs pimlibs
USE_QT=		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
