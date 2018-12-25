# $FreeBSD$

PORTNAME=	print-manager
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	print kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE 4

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	${LOCALBASE}/share/cups/data/testprint:print/cups-filters

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		designer network \
		qmake_build moc_build uic_build rcc_build

post-patch:
	@${REINPLACE_CMD} 's,/usr/share/cups,${LOCALBASE}/share/cups,' \
		${WRKSRC}/libkcups/KCupsRequest.cpp

.include <bsd.port.mk>
