# New ports collection makefile for:	jabberd
# Date created:				29 December 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jabberd
PORTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/jabberd2/
DISTNAME=	${PORTNAME}-2.0s1
DIST_SUBDIR=	jabber

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Online presence and instant messaging server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-libiconv-prefix=${LOCALBASE} \
		--enable-storage='${STORAGE}' \
		--enable-authreg='${AUTHREG}'

STORAGE+=	fs
AUTHREG+=	anon pipe

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/include:${LOCALBASE}/lib
STORAGE+=	pgsql
AUTHREG+=	pgsql
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}/include/mysql:${LOCALBASE}/lib/mysql
STORAGE+=	mysql
AUTHREG+=	mysql
.endif

.if defined(WITH_BDB)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-berkeley-db=${LOCALBASE}/include/db41:${LOCALBASE}/lib
STORAGE+=	db
AUTHREG+=	db
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}/include:${LOCALBASE}/lib
AUTHREG+=	ldap
.endif

MAN8=		c2s.8 jabberd.8 resolver.8 router.8 s2s.8 sm.8

pre-everything::
	@${ECHO}
	@${ECHO} "You can build jabberd with the following options:"
	@${ECHO} "WITH_PGSQL	use PostgreSQL for storage and authentication"
	@${ECHO} "WITH_BDB	use Berkeley DB for storage and authentication"
	@${ECHO} "WITH_MYSQL	use MySQL for storage and authentication"
	@${ECHO} "WITH_LDAP	use LDAP for authentication"
	@${ECHO}

.include <bsd.port.mk>
