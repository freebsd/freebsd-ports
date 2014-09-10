# $FreeBSD$

PORTNAME=	ktp-accounts-kcm
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	3
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE instant messaging account management module

LIB_DEPENDS=	libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:${PORTSDIR}/net-im/telepathy-logger-qt4 \
		libktpcommoninternalsprivate.so:${PORTSDIR}/net-im/ktp-common-internals
RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktp-contactlist:${PORTSDIR}/net-im/ktp-contact-list

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake gettext tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	HAZE IRC JABBER SALUT
OPTIONS_DEFAULT=JABBER

HAZE_DESC=	libpurple protocols support
HAZE_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze

IRC_DESC=	Internet Relay Chat support
IRC_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle

JABBER_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble

SALUT_DESC=	Link-local (serverless) XMPP support
SALUT_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut

.include <bsd.port.mk>
