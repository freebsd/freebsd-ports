# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=	FILESHARING KDNSSD KGET KOPETE KRDC KRFB STRIGI
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FILESHARING_DESC=	Network file sharing via Samba
FILESHARING_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/sambausershareplugin.so:net/kdenetwork4-filesharing

KDNSSD_DESC=		Network monitor for DNS-SD services (Zeroconf)
KDNSSD_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kded_dnssdwatcher.so:net/zeroconf-ioslave

KGET_DESC=		Download manager
KGET_RUN_DEPENDS=	${KDE_PREFIX}/bin/kget:net/kget

KOPETE_DESC=		Multi-protocol instant messenger
KOPETE_RUN_DEPENDS=	${KDE_PREFIX}/bin/kopete:net-im/kopete-kde4

KRDC_DESC=		RDP and VNC client
KRDC_RUN_DEPENDS=	${KDE_PREFIX}/bin/krdc:net/krdc

KRFB_DESC=		Desktop Sharing (VNC server)
KRFB_RUN_DEPENDS=	${KDE_PREFIX}/bin/krfb:net/krfb

STRIGI_DESC=		Strigi analyzers for network-related file formats
STRIGI_RUN_DEPENDS=	${KDE_PREFIX}/lib/strigi/strigita_torrent_analyzer.so:net/kdenetwork4-strigi-analyzers

.include <bsd.port.mk>
