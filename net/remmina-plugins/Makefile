# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
PORTVERSION=	1.0.0
PORTREVISION?=	4
CATEGORIES=	net gnome
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	remmina
GH_COMMIT=	356c033
GH_TAGNAME=	${PORTVERSION}
DISTNAME=	remmina-${PORTVERSION}


MAINTAINER?=	fluffy@FreeBSD.org
COMMENT?=	Remmina plugin system

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

OPTIONS_DEFINE=	KEYRING RDP VNC XDMCP TELEP NX NLS
OPTIONS_DEFAULT=	KEYRING RDP VNC XDMCP TELEP NLS
KEYRING_DESC=	GNOME Keyring plugin
RDP_DESC=	RDP protocol plugin
VNC_DESC=	VNC protocol plugin
XDMCP_DESC=	XDMCP protocol plugin
TELEP_DESC=	Telepathy protocol plugin
NX_DESC=	NX protocol plugin

NO_BUILD=	yes
PATCHDIR=	# none

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKEYRING}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugins-gnome.so:${PORTSDIR}/net/remmina-plugin-gnome
.endif

.if ${PORT_OPTIONS:MRDP}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-rdp.so:${PORTSDIR}/net/remmina-plugin-rdp
.endif

.if ${PORT_OPTIONS:MVNC}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-vnc.so:${PORTSDIR}/net/remmina-plugin-vnc
.endif

.if ${PORT_OPTIONS:MXDMCP}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-xdmcp.so:${PORTSDIR}/net/remmina-plugin-xdmcp
.endif

.if ${PORT_OPTIONS:MTELEP}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-telepathy.so:${PORTSDIR}/net/remmina-plugin-telepathy
.endif

.if ${PORT_OPTIONS:MNX}
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-nx.so:${PORTSDIR}/net/remmina-plugin-nx
.endif

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	${LOCALBASE}/share/locale/bg/LC_MESSAGES/remmina-plugins.mo:${PORTSDIR}/net/remmina-plugin-i18n
.endif

do-install:	# empty

.include <bsd.port.mk>

.endif
