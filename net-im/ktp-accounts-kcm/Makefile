# $FreeBSD$

PORTNAME=	ktp-accounts-kcm
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging account management module

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:net-im/telepathy-logger-qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake gettext tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	HAZE IRC JABBER SALUT
OPTIONS_DEFAULT=JABBER

HAZE_DESC=	libpurple protocols support
HAZE_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-haze:net-im/telepathy-haze

IRC_DESC=	Internet Relay Chat support
IRC_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-idle:net-im/telepathy-idle

JABBER_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-gabble:net-im/telepathy-gabble

SALUT_DESC=	Link-local (serverless) XMPP support
SALUT_RUN_DEPENDS=	${LOCALBASE}/libexec/telepathy-salut:net-im/telepathy-salut

.include <bsd.port.mk>
