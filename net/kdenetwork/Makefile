# $FreeBSD$

PORTNAME=	kdenetwork
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications (meta port)

USES=		kde:5 metaport
USE_QT5=	#

OPTIONS_DEFINE=	FILESHARING KGET KRDC KRFB
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NKOPETE}

FILESHARING_DESC=	Network file sharing via Samba
FILESHARING_RUN_DEPENDS=	kdenetwork-filesharing>=${KDE_APPLICATIONS_VERSION}:net/kdenetwork-filesharing

KGET_DESC=		Download manager
KGET_RUN_DEPENDS=	kget>=${KDE_APPLICATIONS_VERSION}:net/kget

# Kopete will be added with the 18.04 update
# KOPETE_DESC=		Multi-protocol instant messenger
# KOPETE_RUN_DEPENDS=	kopete>=${KDE_APPLICATIONS_VERSION}:net-im/kopete

KRDC_DESC=		RDP and VNC client
KRDC_RUN_DEPENDS=	krdc>=${KDE_APPLICATIONS_VERSION}:net/krdc

KRFB_DESC=		Desktop Sharing (VNC server)
KRFB_RUN_DEPENDS=	krfb>=${KDE_APPLICATIONS_VERSION}:net/krfb

.include <bsd.port.mk>
