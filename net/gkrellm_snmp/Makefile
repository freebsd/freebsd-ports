# New ports collection makefile for:   gkrellm_snmp
# Date created:        10/09/2000
# Whom:                Eike Bernhardt <eike.bernhardt@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gkrellm_snmp
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	eike.bernhardt@gmx.de
COMMENT=	A gkrellm SNMP Monitor

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp4
BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/gkrellm_snmp.so
USE_X_PREFIX=   yes
USE_GNOME=	imlib
MAKE_ENV=	GKRELLM_INCLUDE="-I${X11BASE}/include/gkrellm/" \
		PLUGIN_DIR="${X11BASE}/libexec/gkrellm/plugins/"

.include <bsd.port.mk>
