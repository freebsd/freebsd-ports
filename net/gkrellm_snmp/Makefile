# New ports collection makefile for:   gkrellm_snmp
# Date created:        10/09/2000
# Whom:                Eike Bernhardt <eike.bernhardt@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gkrellm_snmp
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	eike.bernhardt@gmx.de

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib \
		snmp.4:${PORTSDIR}/net/ucd-snmp
BUILD_DEPENDS=  ${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=    gkrellm:${PORTSDIR}/sysutils/gkrellm

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_X_PREFIX=   yes
MAKE_ENV=       GTK_CONFIG="${GTK_CONFIG}" \
		GKRELLM_INCLUDE="-I${X11BASE}/include/gkrellm/" \
		PLUGIN_DIR="${X11BASE}/libexec/gkrellm/plugins/"

.include <bsd.port.mk>
