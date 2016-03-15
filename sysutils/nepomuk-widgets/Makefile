# $FreeBSD$

PORTNAME=	nepomuk-widgets
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The NepomukWidget libraries

USE_KDE4=	kdelibs kdeprefix automoc4 soprano nepomuk-core
USES=		cmake:outsource tar:xz
USE_QT4=	corelib dbus gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
