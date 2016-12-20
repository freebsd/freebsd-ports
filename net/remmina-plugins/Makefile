# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.0-rcgit.16
PORTREVISION=	1
CATEGORIES=	net gnome

PATCH_SITES=	https://github.com/FreeRDP/Remmina/commit/
PATCHFILES=	9b783595bd7fbfc39d1194d28110519c49dcaecc.patch:-p1

MAINTAINER?=	woodsb02@FreeBSD.org
COMMENT?=	Remmina plugin system

LICENSE?=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	Remmina

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

USES=	metaport

OPTIONS_DEFINE=		KEYRING NX RDP TELEP VNC XDMCP
OPTIONS_DEFAULT=	KEYRING RDP TELEP VNC XDMCP
KEYRING_DESC=		GNOME Keyring plugin
RDP_DESC=		Remote Desktop Protocol plugin
VNC_DESC=		VNC protocol plugin
XDMCP_DESC=		XDMCP protocol plugin
TELEP_DESC=		Telepathy protocol plugin
NX_DESC=		NX protocol plugin

KEYRING_RUN_DEPENDS=	remmina-plugin-gnome>=0:net/remmina-plugin-gnome
NX_RUN_DEPENDS=		remmina-plugin-nx>=0:net/remmina-plugin-nx
RDP_RUN_DEPENDS=	remmina-plugin-rdp>=0:net/remmina-plugin-rdp
TELEP_RUN_DEPENDS=	remmina-plugin-telepathy>=0:net/remmina-plugin-telepathy
VNC_RUN_DEPENDS=	remmina-plugin-vnc>=0:net/remmina-plugin-vnc
XDMCP_RUN_DEPENDS=	remmina-plugin-xdmcp>=0:net/remmina-plugin-xdmcp

do-patch:

.include <bsd.port.mk>

.endif
