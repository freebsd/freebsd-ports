# New ports collection makefile for:	teapop
# Date created:			18 May 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	teapop
PORTVERSION=	0.3.7
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/ \
		http://www.toontown.org/pub/teapop/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another RFC1939 compliant POP3 server

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-flock

## Available knobs:
## General options
##   WITHOUT_IPV6: disable IPv6 support
##   WITH_TCPD: enable support for tcpd/tcpwrapper
##   WITHOUT_APOP: don't allow users to authenticate with APOP
##   WITHOUT_VPOP: don't support virtual domains
##   WITH_DRAC: enable support for DRAC
##   WITH_POPAUTHFILE: enable support for a popauth file
##   POPAUTH_FILE: popauth file name (default : ${PREFIX}/etc/teapop.popauth)

POPAUTH_FILE?=		${PREFIX}/etc/teapop.popauth

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_TCPD)
CONFIGURE_ARGS+=	--with-tcpd
.endif

.if defined(WITHOUT_APOP)
CONFIGURE_ARGS+=	--disable-apop
.endif

.if defined(WITHOUT_VPOP)
CONFIGURE_ARGS+=	--disable-vpop
.endif

.if defined(WITH_DRAC)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

.if defined(WITH_POPAUTHFILE)
CONFIGURE_ARGS+=	--enable-popauth-file=${POPAUTH_FILE}
.endif

MAN8=		teapop.8

.include <bsd.port.pre.mk>

## Authentication backend
##   WITH_LDAP: add support for authentication through OpenLDAP server
##   WITH_LDAP_VER: OpenLDAP version to use (can be: 20 for 2.0, 21 for 2.1, 22 for 2.2 ; default 21)
##   WITH_MYSQL: enable support for authentication from MySQL database
##   WITH_MYSQL_VER: MySQL version to use (can be: 323 for 3.23, 40 for 4.0, 4.1 for 4.1 ; default 323)
##   WITH_PGSQL: enable support for authentication from PostgreSQL database

MYSQL323_LIBVER=10
MYSQL40_LIBVER=	12
MYSQL41_LIBVER=	14
WITH_LDAP_VER?=	21

# MySQL deps hack (revision 2)
.if defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL_323_LIBVER})
MYSQL_VER=	323
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL40_LIBVER})
MYSQL_VER=	40
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL41_LIBVER})
MYSQL_VER=	41
.else
MYSQL_VER=	323
.endif

LDAP_VER=	${WITH_LDAP_VER}

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql7
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
LIB_DEPENDS+=		mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
.endif

.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-ldap=openldap
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap${LDAP_VER}-client
.endif

show-options:
	@${EGREP} '^##' ${.CURDIR}/Makefile | ${SED} 's/##//'

post-install:
	@${ECHO} ""
	@${ECHO} "------------------------------------------------------------------------"
	@${ECHO} "===> Be sure to copy ${LOCALBASE}/etc/teapop.passwd.sample to"
	@${ECHO} "===> ${LOCALBASE}/etc/teapop.passwd before using teapop"
	@${ECHO} "------------------------------------------------------------------------"
	@${ECHO} ""

.include <bsd.port.post.mk>
