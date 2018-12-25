# $FreeBSD$

PORTNAME=	baloo-widgets
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The BalooWidgets library

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 baloo kfilemetadata
USE_QT=		corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
