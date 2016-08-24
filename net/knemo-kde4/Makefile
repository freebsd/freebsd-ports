# $FreeBSD$

PORTNAME=	knemo
PORTVERSION=	0.7.7
CATEGORIES=	net kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	12956-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE network monitor

USES=		cmake gettext kde:4 shebangfix tar:xz
SHEBANG_FILES=	src/kconf_update/*.pl
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_KDE=	kdelibs workspace automoc4

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
