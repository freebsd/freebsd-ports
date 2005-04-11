# New ports collection makefile for:   openradius
# Date created:        23 May 2003
# Whom:                Adam Jette <jettea46@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	openradius
PORTVERSION=	0.9.10
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
# Configuration, copy over to sample files
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for FILE in dictionary behaviour configuration
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${PREFIX}/etc/${PORTNAME}/${FILE}.sample
.endfor
# Copy over legacy config files to sample
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/legacy
.for FILE in clients nases realms users
	${INSTALL_DATA} ${WRKSRC}/etc/legacy/${FILE} \
		${PREFIX}/etc/${PORTNAME}/legacy/${FILE}.sample
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
