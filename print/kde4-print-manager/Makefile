# $FreeBSD$

PORTNAME=	print-manager
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	print kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE 4

LIB_DEPENDS=    libcups.so:${PORTSDIR}/print/cups-client

USES=		cmake:outsource tar:xz
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	designer network \
		qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
