# $FreeBSD$

PORTNAME=	ktp-accounts-kcm
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE instant messaging account management module

LIB_DEPENDS=	telepathy-qt4:${PORTSDIR}/net-im/telepathy-qt4 \
		telepathy-logger-qt4:${PORTSDIR}/net-im/telepathy-logger-qt4 \
		ktpcommoninternalsprivate:${PORTSDIR}/net-im/ktp-common-internals
RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktp-contactlist:${PORTSDIR}/net-im/ktp-contact-list

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	HAZE IRC JABBER SALUT
OPTIONS_DEFAULT=JABBER

HAZE_DESC=	libpurple protocols support
IRC_DESC=	Internet Relay Chat support
SALUT_DESC=	Link-local (serverless) XMPP support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHAZE}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-haze:${PORTSDIR}/net-im/telepathy-haze
.endif

.if ${PORT_OPTIONS:MIRC}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-idle:${PORTSDIR}/net-im/telepathy-idle
.endif

.if ${PORT_OPTIONS:MJABBER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-gabble:${PORTSDIR}/net-im/telepathy-gabble
.endif

.if ${PORT_OPTIONS:MSALUT}
RUN_DEPENDS+=	${LOCALBASE}/libexec/telepathy-salut:${PORTSDIR}/net-im/telepathy-salut
.endif

.include <bsd.port.mk>
