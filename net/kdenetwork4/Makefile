# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde
DISTFILES=	#

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	FILESHARING KDNSSD KGET KOPETE KRDC KRFB STRIGI
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FILESHARING_DESC=	Network file sharing via Samba
FILESHARING_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/sambausershareplugin.so:${PORTSDIR}/net/kdenetwork4-filesharing

KDNSSD_DESC=		Network monitor for DNS-SD services (Zeroconf)
KDNSSD_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kded_dnssdwatcher.so:${PORTSDIR}/net/zeroconf-ioslave

KGET_DESC=		Download manager
KGET_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kget:${PORTSDIR}/net/kget

KOPETE_DESC=		Multi-protocol instant messenger
KOPETE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kopete:${PORTSDIR}/net-im/kopete-kde4

KRDC_DESC=		RDP and VNC client
KRDC_RUN_DEPENDS=	${KDE4_PREFIX}/bin/krdc:${PORTSDIR}/net/krdc

KRFB_DESC=		Desktop Sharing (VNC server)
KRFB_RUN_DEPENDS=	${KDE4_PREFIX}/bin/krfb:${PORTSDIR}/net/krfb

STRIGI_DESC=		Strigi analyzers for network-related file formats
STRIGI_RUN_DEPENDS=	${KDE4_PREFIX}/lib/strigi/strigita_torrent_analyzer.so:${PORTSDIR}/net/kdenetwork4-strigi-analyzers

.include <bsd.port.mk>
