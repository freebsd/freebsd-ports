# New ports collection makefile for:   yptransitd
# Date created: 	26 September 2002
# Whom: 		Michael Joyner <mjoyner@hq.dyns.cx>
#
# $FreeBSD$
#

PORTNAME=	yptransitd
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://unc.dl.sourceforge.net/sourceforge/yptransitd/

MAINTAINER=	mjoyner@hq.dyns.cx
COMMENT=	A replacement for nss_ldap

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap20-client

USE_BISON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap-prefix=${LOCALBASE}

post-install:
	@ ${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>
