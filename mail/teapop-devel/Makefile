# New ports collection makefile for:	teapop-devel
# Date created:				7/08/2003
# Whom:					sheepkiller@cultdeadsheep.org
#
# $FreeBSD$
#

PORTNAME=	teapop
PORTVERSION=	20030414
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/snapshots/ \
		http://www.toontown.org/pub/teapop/snapshots/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another RFC1939 compliant POP3 server

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-flock

LATEST_LINK=	teapop-devel

##
## Available knobs:
## General options
##   WITHOUT_IPV6: disable IPv6 support
##   WITH_TCPWRAPPERS: enable the use of tcp_wrappers
##   WITHOUT_APOP: don't allow users to authenticate with APOP
##   WITHOUT_VPOP: don't support virtual domains
##   WITH_DRAC: enable support for DRAC
##   WITH_POPAUTHFILE: enable support for a popauth file
##   POPAUTH_FILE: popauth file name (default : ${PREFIX}/etc/teapop.popauth)

POPAUTH_FILE?=		${PREFIX}/etc/teapop.popauth

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_TCPWRAPPERS)
CONFIGURE_ARGS+=	--enable-tcp_wrappers
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

##
## Authentication backend
##   WITH_OPENLDAP: add support for authentication through OpenLDAP server
##   WITH_MYSQL: enable support for authentication from MySQL database
##   WITH_PGSQL: enable support for authentication from PostgreSQL database
##

.if defined(WITH_PGSQL)
USE_PGSQL=		YES
CONFIGURE_ARGS+=	--with-pgsql
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap=openldap
.endif

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG} "===> Be sure to copy ${LOCALBASE}/etc/teapop.passwd.sample to"
	@${ECHO_MSG} "===> ${LOCALBASE}/etc/teapop.passwd before using teapop"
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
