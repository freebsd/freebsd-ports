# $FreeBSD$

PORTNAME=	ktp
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PORTNAME}-desktop-applets-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE instant messaging Plasma applets

LIB_DEPENDS=	telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4 \
		ktpcommoninternalsprivate:${PORTSDIR}/net-im/ktp-common-internals

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib declarative \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
