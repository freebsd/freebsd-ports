# New ports collection makefile for: app_ldap
# Date created:		15 April 2007
# Whom:			Matthias Fechner <idefix@fechner.net>
#
# $FreeBSD$
#

PORTNAME=	asterisk-app-ldap
DISTVERSION=	2.0rc1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.mezzo.net/asterisk/
DISTNAME=	app_ldap-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	idefix@fechner.net
COMMENT=	LDAPget application module for the Asterisk PBX 1.4

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes
USE_ICONV=	yes
USE_OPENLDAP=	yes

.include <bsd.port.mk>
