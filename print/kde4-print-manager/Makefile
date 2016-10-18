# $FreeBSD$

PORTNAME=	print-manager
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	print kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE 4

LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	${LOCALBASE}/share/cups/data/testprint:print/cups-filters

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	designer network \
		qmake_build moc_build uic_build rcc_build

post-patch:
	@${REINPLACE_CMD} 's,/usr/share/cups,${LOCALBASE}/share/cups,' \
		${WRKSRC}/libkcups/KCupsRequest.cpp

.include <bsd.port.mk>
