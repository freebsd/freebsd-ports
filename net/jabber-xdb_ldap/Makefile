# New ports collection makefile for:	jabber-xdb_ldap
# Date created:			03 January 2004
# Whom:				Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	xdb_ldap
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/xdb_ldap/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	martijn@pacno.net
COMMENT=	Jabber xdb backend for an LDAP directory

BUILD_DEPENDS=	${NON_EXISTENT}:${PORTSDIR}/net/jabber:configure

USE_GMAKE=	yes
USE_OPENLDAP=	yes

FORBIDDEN=	"Site is down after intrusion. Probably this project will never be revived"

WRKSRC=		${WRKDIR}/${PORTNAME}/src

.include <bsd.port.pre.mk>

JABBER_SRC!=	cd ${PORTSDIR}/net/jabber && make -V WRKSRC
MAKE_ENV=	JABBER_SRC=${JABBER_SRC}

do-install:
	${MKDIR} ${PREFIX}/lib/jabber
	${INSTALL_DATA} ${WRKSRC}/xdb_ldap.so ${PREFIX}/lib/jabber/
	${INSTALL_DATA} ${WRKSRC}/../jabber-xdb.xml ${PREFIX}/etc/jabber-xdb.xml.sample
	${MKDIR} ${PREFIX}/etc/openldap/schema
	${INSTALL_DATA} ${WRKSRC}/../jabber.schema ${PREFIX}/etc/openldap/schema/jabber.schema.default

.include <bsd.port.post.mk>
