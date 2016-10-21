# $FreeBSD$

PORTNAME=	nepomuk-widgets
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The NepomukWidget libraries

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4 soprano nepomuk-core
USE_QT4=	corelib dbus gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
