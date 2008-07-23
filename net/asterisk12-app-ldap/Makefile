# New ports collection makefile for: app_ldap
# Date created:		30 July 2006
# Whom:			Matthias Fechner <idefix@fechner.net>
#
# $FreeBSD$
#

PORTNAME=	asterisk12-app-ldap
DISTVERSION=	1.0rc6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.mezzo.net/asterisk/
DISTNAME=	app_ldap-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	idefix@fechner.net
COMMENT=	LDAPget application module for the Asterisk PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk12

USE_GMAKE=	yes
USE_ICONV=	yes
USE_OPENLDAP=	yes

.include <bsd.port.mk>
