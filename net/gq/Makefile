# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	0.2.3
CATEGORIES=     net
MASTER_SITES=	http://biot.com/gq/download/

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		ldap.1:${PORTSDIR}/net/openldap

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share --with-ldap=${LOCALBASE}

.include <bsd.port.mk>
