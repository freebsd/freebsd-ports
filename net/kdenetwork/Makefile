# $FreeBSD$

PORTNAME=	kdenetwork
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications (meta port)

USES=		kde:5 metaport qt:5
USE_QT=		#

OPTIONS_DEFINE=	FILESHARING KRDC KRFB KOPETE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FILESHARING_DESC=	Network file sharing via Samba
FILESHARING_RUN_DEPENDS=	kdenetwork-filesharing>=${KDE_APPLICATIONS_VERSION}:net/kdenetwork-filesharing

KRDC_DESC=		RDP and VNC client
KRDC_RUN_DEPENDS=	krdc>=${KDE_APPLICATIONS_VERSION}:net/krdc

KRFB_DESC=		Desktop Sharing (VNC server)
KRFB_RUN_DEPENDS=	krfb>=${KDE_APPLICATIONS_VERSION}:net/krfb

KOPETE_DESC=		Multi-protocol instant messenger
KOPETE_RUN_DEPENDS=	kopete:net-im/kopete

.include <bsd.port.mk>
