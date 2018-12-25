# $FreeBSD$

PORTNAME=	nepomuk-widgets
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	6
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The NepomukWidget libraries

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 soprano nepomuk-core
USE_QT=		corelib dbus gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
