# New ports collection makefile for:	remmina-plugins
# Date created:				24 June 2010
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	remmina-plugins
PORTVERSION=	0.9.2
CATEGORIES=	net gnome
MASTER_SITES=	# Empty
DISTFILES?=	# Empty

MAINTAINER=	avl@FreeBSD.org
COMMENT?=	Remmina plugin system

.if defined(PKGNAMESUFFIX)
.include "${.CURDIR}/../remmina-plugins/bsd.plugin.mk"
.else

OPTIONS=	RDP	"Install RDP protocol plugin"	on \
		VNC	"Install VNC protocol plugin"	on \
		XDMCP	"Install XDMCP protocol plugin"	on \
		TELEP	"Install Telepathy protocol plugin"	on

NO_BUILD=	yes
PATCHDIR=	# none

.include <bsd.port.options.mk>

.if !defined(WITHOUT_RDP)
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-rdp.so:${PORTSDIR}/net/remmina-plugin-rdp
.endif

.if !defined(WITHOUT_VNC)
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-vnc.so:${PORTSDIR}/net/remmina-plugin-vnc
.endif

.if !defined(WITHOUT_XDMCP)
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-xdmcp.so:${PORTSDIR}/net/remmina-plugin-xdmcp
.endif

.if !defined(WITHOUT_TELEP)
RUN_DEPENDS+=	${LOCALBASE}/lib/remmina/plugins/remmina-plugin-telepathy.so:${PORTSDIR}/net/remmina-plugin-telepathy
.endif

do-install:	# empty

.include <bsd.port.mk>

.endif
