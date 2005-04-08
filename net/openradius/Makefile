# New ports collection makefile for:   openradius
# Date created:        23 May 2003
# Whom:                Adam Jette <jettea46@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	openradius
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.xs4all.nl/~evbergen/openradius/download/ \
		http://www.mirrors.wiretapped.net/security/authentication/radius/openradius/

MAINTAINER=	jettea46@yahoo.com
COMMENT=	A RADIUS server with some actual documentation

CONFLICTS=	freeradius-0.* gnu-radius-1.* radiusd-cistron-1.*

CC?=		gcc
CXX?=		g++
USE_GMAKE=	yes

OPTIONS=	LDAP	"With LDAP user database" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
SCRIPTS_ENV+=	USE_LDAP=yes
.else
PLIST_SUB+=	LDAP="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
