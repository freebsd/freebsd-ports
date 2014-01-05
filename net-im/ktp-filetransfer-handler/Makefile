# $FreeBSD$

PORTNAME=	ktp-filetransfer-handler
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE instant messaging file transfer handler

LIB_DEPENDS=	telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4 \
		ktpcommoninternalsprivate:${PORTSDIR}/net-im/ktp-common-internals

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
USE_BZIP2=	yes

.include <bsd.port.mk>
