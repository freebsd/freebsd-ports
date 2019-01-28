# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
DISTVERSION=	1.2.31.4
PORTREVISION=	1
CATEGORIES=	net gnome

MAINTAINER?=	woodsb02@FreeBSD.org
COMMENT?=	Remmina plugin system

LICENSE?=	GPLv2+

.if defined(PKGNAMESUFFIX)

USE_GITLAB=	yes
GL_ACCOUNT=	Remmina
GL_PROJECT=	Remmina
GL_COMMIT=	65d552c9becc957cae124ab5c26562cf22c052b9

.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"

.else

USES=	metaport

OPTIONS_DEFINE=		EXEC KEYRING NX RDP TELEP VNC XDMCP
OPTIONS_DEFAULT=	EXEC KEYRING RDP TELEP VNC XDMCP
EXEC_DESC=		Plugin to execute a command
KEYRING_DESC=		GNOME Keyring plugin
RDP_DESC=		Remote Desktop Protocol plugin
VNC_DESC=		VNC protocol plugin
XDMCP_DESC=		XDMCP protocol plugin
TELEP_DESC=		Telepathy protocol plugin
NX_DESC=		NX protocol plugin

EXEC_RUN_DEPENDS=	remmina-plugin-exec>=0:net/remmina-plugin-exec
KEYRING_RUN_DEPENDS=	remmina-plugin-secret>=0:net/remmina-plugin-secret
NX_RUN_DEPENDS=		remmina-plugin-nx>=0:net/remmina-plugin-nx
RDP_RUN_DEPENDS=	remmina-plugin-rdp>=0:net/remmina-plugin-rdp
TELEP_RUN_DEPENDS=	remmina-plugin-telepathy>=0:net/remmina-plugin-telepathy
VNC_RUN_DEPENDS=	remmina-plugin-vnc>=0:net/remmina-plugin-vnc
XDMCP_RUN_DEPENDS=	remmina-plugin-xdmcp>=0:net/remmina-plugin-xdmcp

.include <bsd.port.mk>

.endif
