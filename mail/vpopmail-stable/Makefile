# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	4.9.8
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/vpopmail/

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	--enable-qmail-dir=${QMAIL_DIR} \
		--enable-tcprules-bin=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${PREFIX}/vpopmail/etc/tcp.smtp

#
# User-configurable variables
#
# Define these to change from the default behaviour
#
# WITH_PASSWD   - allow authentication off /etc/passwd
# WITH_MYSQL	- allow authentitation via mysql
# WITH_APOP     - allow apop authentication
# WITHOUT_ROAMING - disallow roaming users
#
# Set these to the values you'd prefer
#
# HARDQUOTA     - size of hard quota, or 'n' for no hard quota
# RELAYCLEAR    - time in minutes before clearing relay hole (requires roaming)
# DEFAULT_DOMAIN - default domain for non-vhost lookups
# LOGLEVEL	- n - no logging, y - log all,
#                 e - log errors, p - log passwords in errors
# APOPFILE	- location of apop secrets file
# QMAIL_DIR     - location of qmail directory
# PREFIX	- installation area for vpopmail (see comment below)
#

HARDQUOTA?=	10000000
RELAYCLEAR?=	30
LOGLEVEL?=	y
APOPFILE?=	/usr/local/vpopmail/etc/apop-secrets

.if exists(${LOCALBASE}/qmail/bin/qmail-send)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

# Uncomment this, or set PREFIX to /home if you have an existing
# vpopmail install with the vpopmail users' home directory set to
# /home/vpopmail - package rules dictate we default to /usr/local/vpopmail
#
#PREFIX?=	/home

# End of user-configurable variables

#
# Some suggestions from Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#

CONFIGURE_ARGS+=	--enable-hardquota=${HARDQUOTA} \
			--enable-logging=${LOGLEVEL}

.if !defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd=n
.endif

.if defined(WITH_APOP)
CONFIGURE_ARGS+=	--enable-apop=y \
			--enable-apop-file=${APOPFILE}
.else
CONFIGURE_ARGS+=	--enable-apop=n
.endif

.if !defined(WITH_SQWEBMAIL)
CONFIGURE_ARGS+=	--enable-sqwebmail-pass=n
.endif

.if !defined(WITHOUT_ROAMING)
CONFIGURE_ARGS+=	--enable-roaming-users=y \
			--enable-relay-clear-minutes=${RELAYCLEAR}
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--enable-mysql=y \
			--enable-sqlincdir=${LOCALBASE}/include/mysql \
			--enable-sqllibdir=${LOCALBASE}/lib/mysql
.endif

.if defined(DEFAULT_DOMAIN)
CONFIGURE_ARGS+=	--enable-default-domain=${DEFAULT_DOMAIN}
.endif

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX}/vpopmail ${PERL5} ${PKGINSTALL}

.include <bsd.port.mk>
