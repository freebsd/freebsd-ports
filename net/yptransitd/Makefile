# New ports collection makefile for:   yptransitd
# Date created: 	26 September 2002
# Whom: 		Michael Joyner <mjoyner@hq.dyns.cx>
#
# $FreeBSD$
#

PORTNAME=	yptransitd
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	yptransitd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for nss_ldap

USE_OPENLDAP=	yes

USE_BISON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap-prefix=${LOCALBASE}

post-install:
	@ ${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>
