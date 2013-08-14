# $FreeBSD$

PORTNAME=	ktp-auth-handler
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KWallet integration module for KDE Telepathy

LIB_DEPENDS=	qjson:${PORTSDIR}/devel/qjson \
		qca:${PORTSDIR}/devel/qca \
		telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4 \
		ktpcommoninternalsprivate:${PORTSDIR}/net-im/ktp-common-internals

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib dbus gui xml webkit \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
USE_BZIP2=	yes

.include <bsd.port.mk>
