# New ports collection makefile for: app_ldap
# Date created:		30 July 2006
# Whom:			Matthias Fechner <idefix@fechner.net>
#
# $FreeBSD$
#

PORTNAME=	app_ldap
DISTVERSION=	1.0rc6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.mezzo.net/asterisk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	idefix@fechner.net
COMMENT=	LDAPget application module for the Asterisk PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk12 \
		${LOCALBASE}/lib/libldap.so:${PORTSDIR}/net/openldap23-client \
		${LOCALBASE}/lib/libiconv.so:${PORTSDIR}/converters/libiconv

USE_GMAKE=	yes

.include <bsd.port.mk>
