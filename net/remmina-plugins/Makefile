# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
DISTVERSION=	1.3.9
CATEGORIES=	net gnome

MAINTAINER?=	woodsb02@FreeBSD.org
COMMENT?=	Remmina plugin system

LICENSE?=	GPLv2+

.if defined(PKGNAMESUFFIX)

USE_GITLAB=	yes
GL_ACCOUNT=	Remmina
GL_PROJECT=	Remmina
GL_COMMIT=	0606fee3f396e28d18dedf202fedcb064ce27ee6

.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"

.else

USES=	metaport

OPTIONS_DEFINE=		EXEC KEYRING NX RDP SPICE ST VNC WWW XDMCP
OPTIONS_DEFAULT=	EXEC KEYRING NX RDP SPICE ST VNC WWW XDMCP
EXEC_DESC=		Plugin to execute a command
KEYRING_DESC=		GNOME Keyring plugin
NX_DESC=		NX protocol plugin
RDP_DESC=		Remote Desktop Protocol plugin
SPICE_DESC=		Spice protocol plugin
ST_DESC=		(Simple) Terminal Plugin
VNC_DESC=		VNC protocol plugin
WWW_DESC=		Plugin to open an authenticated web browser
XDMCP_DESC=		XDMCP protocol plugin

EXEC_RUN_DEPENDS=	remmina-plugin-exec>=0:net/remmina-plugin-exec
KEYRING_RUN_DEPENDS=	remmina-plugin-secret>=0:net/remmina-plugin-secret
NX_RUN_DEPENDS=		remmina-plugin-nx>=0:net/remmina-plugin-nx
RDP_RUN_DEPENDS=	remmina-plugin-rdp>=0:net/remmina-plugin-rdp
SPICE_RUN_DEPENDS=	remmina-plugin-spice>=0:net/remmina-plugin-spice
ST_RUN_DEPENDS=		remmina-plugin-st>=0:net/remmina-plugin-st
VNC_RUN_DEPENDS=	remmina-plugin-vnc>=0:net/remmina-plugin-vnc
WWW_RUN_DEPENDS=	remmina-plugin-www>=0:net/remmina-plugin-www
XDMCP_RUN_DEPENDS=	remmina-plugin-xdmcp>=0:net/remmina-plugin-xdmcp

.include <bsd.port.mk>

.endif
