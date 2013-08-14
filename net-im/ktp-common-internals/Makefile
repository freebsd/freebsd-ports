# $FreeBSD$

PORTNAME=	ktp-common-internals
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE Telepathy internal library

LIB_DEPENDS=	telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4 \
		telepathy-logger-qt4:${PORTSDIR}/net-im/telepathy-logger-qt4
RUN_DEPENDS=	${LOCALBASE}/libexec/mission-control-5:${PORTSDIR}/net-im/telepathy-mission-control

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	declarative script \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
