# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	0.4.0
CATEGORIES=	net
MASTER_SITES=	http://biot.com/gq/download/

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap=${LOCALBASE}

.include <bsd.port.mk>
