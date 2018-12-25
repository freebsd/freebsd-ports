# $FreeBSD$

PORTNAME=	parley
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	misc kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Vocabulary trainer for KDE 4

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs libkeduvocdocument attica automoc4
USE_QT=		corelib gui moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xrender

.include <bsd.port.mk>
