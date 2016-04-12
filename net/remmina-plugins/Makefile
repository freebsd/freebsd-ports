# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
PORTVERSION=	1.0.0
PORTREVISION?=	4
CATEGORIES=	net gnome

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Remmina plugin system

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	Remmina

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

OPTIONS_DEFINE=	KEYRING VNC XDMCP TELEP NX NLS
OPTIONS_DEFAULT=	KEYRING VNC XDMCP TELEP NLS
KEYRING_DESC=	GNOME Keyring plugin
VNC_DESC=	VNC protocol plugin
XDMCP_DESC=	XDMCP protocol plugin
TELEP_DESC=	Telepathy protocol plugin
NX_DESC=	NX protocol plugin

NO_BUILD=	yes
PATCHDIR=	# none

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKEYRING}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugins-gnome.so:net/remmina-plugin-gnome
.endif

.if ${PORT_OPTIONS:MVNC}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-vnc.so:net/remmina-plugin-vnc
.endif

.if ${PORT_OPTIONS:MXDMCP}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-xdmcp.so:net/remmina-plugin-xdmcp
.endif

.if ${PORT_OPTIONS:MTELEP}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-telepathy.so:net/remmina-plugin-telepathy
.endif

.if ${PORT_OPTIONS:MNX}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-nx.so:net/remmina-plugin-nx
.endif

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	${LOCALBASE}/share/locale/bg/LC_MESSAGES/remmina-plugins.mo:net/remmina-plugin-i18n
.endif

do-install:	# empty

.include <bsd.port.mk>

.endif
