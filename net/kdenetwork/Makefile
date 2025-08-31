PORTNAME=	kdenetwork
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications (meta port)
WWW=		https://apps.kde.org/categories/internet/

USES=		kde:6 metaport qt:6

OPTIONS_DEFINE=	FILESHARING KGET KRDC KRFB
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FILESHARING_DESC=	Network file sharing via Samba
FILESHARING_RUN_DEPENDS=	kdenetwork-filesharing>=${KDE_APPLICATIONS_VERSION}:net/kdenetwork-filesharing

KGET_DESC=		Download manager
KGET_RUN_DEPENDS=	kget>=${KDE_APPLICATIONS_VERSION}:net/kget

KRDC_DESC=		RDP and VNC client
KRDC_RUN_DEPENDS=	krdc>=${KDE_APPLICATIONS_VERSION}:net/krdc

KRFB_DESC=		Desktop Sharing (VNC server)
KRFB_RUN_DEPENDS=	krfb>=${KDE_APPLICATIONS_VERSION}:net/krfb

KTORRENT_DESC=		BitTorrent client for KDE
KTORRENT_RUN_DEPENDS=	ktorrent>=${KDE_APPLICATIONS_VERSION}:net-p2p/ktorrent

.include <bsd.port.mk>
