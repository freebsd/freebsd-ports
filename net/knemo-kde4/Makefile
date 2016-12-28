# $FreeBSD$

PORTNAME=	knemo
PORTVERSION=	0.7.7
CATEGORIES=	net kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	12956-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE network monitor

BROKEN_FreeBSD_11=	does not build due to access to kernel-private structure (error: member access into incomplete type 'struct in6_ifaddr')
BROKEN_FreeBSD_12=	does not build due to access to kernel-private structure (error: member access into incomplete type 'struct in6_ifaddr')

USES=		cmake gettext kde:4 shebangfix tar:xz
SHEBANG_FILES=	src/kconf_update/*.pl
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_KDE=	kdelibs workspace automoc4

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
