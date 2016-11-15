# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.0-rcgit.16
CATEGORIES=	net gnome

MAINTAINER?=	woodsb02@FreeBSD.org
COMMENT?=	Remmina plugin system

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	Remmina

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

USES=	metaport

OPTIONS_DEFINE=		KEYRING NX TELEP VNC XDMCP
OPTIONS_DEFAULT=	KEYRING TELEP VNC XDMCP
KEYRING_DESC=		GNOME Keyring plugin
VNC_DESC=		VNC protocol plugin
XDMCP_DESC=		XDMCP protocol plugin
TELEP_DESC=		Telepathy protocol plugin
NX_DESC=		NX protocol plugin

KEYRING_RUN_DEPENDS=	remmina-plugin-gnome>=0:net/remmina-plugin-gnome
NX_RUN_DEPENDS=		remmina-plugin-nx>=0:net/remmina-plugin-nx
TELEP_RUN_DEPENDS=	remmina-plugin-telepathy>=0:net/remmina-plugin-telepathy
VNC_RUN_DEPENDS=	remmina-plugin-vnc>=0:net/remmina-plugin-vnc
XDMCP_RUN_DEPENDS=	remmina-plugin-xdmcp>=0:net/remmina-plugin-xdmcp

.include <bsd.port.mk>

.endif
