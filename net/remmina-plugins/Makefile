# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	remmina-plugins
PORTVERSION=	0.9.2
PORTREVISION?=	1
CATEGORIES=	net gnome
MASTER_SITES=	# Empty
DISTFILES?=	# Empty

MAINTAINER=	fluffy@FreeBSD.org
COMMENT?=	Remmina plugin system

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

OPTIONS_DEFINE=	RDP VNC XDMCP TELEP
OPTIONS_DEFAULT=	RDP VNC XDMCP TELEP
RDP_DESC=	RDP protocol plugin
VNC_DESC=	VNC protocol plugin
XDMCP_DESC=	XDMCP protocol plugin
TELEP_DESC=	Telepathy protocol plugin

NO_BUILD=	yes
PATCHDIR=	# none

.include <bsd.port.options.mk>

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

do-install:	# empty

.include <bsd.port.mk>

.endif
