# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	5.2.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/vpopmail/
PKGNAMESUFFIX=	-stable

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"Easy virtual domain and authentication package for use with qmail"

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES
USE_PERL5_BUILD=	YES

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

CONFIGURE_ENV+=	VCFGDIR="${VCFGDIR}"
CONFIGURE_ARGS=	--enable-qmaildir=${QMAIL_DIR} \
		--enable-tcprules-bin=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${PREFIX}/vpopmail/etc/tcp.smtp

#
# User-configurable variables
#
# Define these to change from the default behaviour
#
# WITH_PASSWD   - allow authentication off /etc/passwd
# WITH_MD5_PASSWORDS - store encrypted passwords in MD5 format
# WITH_MYSQL	- allow authentitation via mysql
# WITH_MYSQL_LARGE_SITE - enables large site layout
# WITH_CLEAR_PASSWD - store passwords in plaintext into the MySQL db
# WITH_APOP     - allow apop authentication
# WITHOUT_ROAMING - disallow roaming users
# WITH_IP_ALIAS - enables IP aliasing
# WITH_DELIVER_FILTER - enables the experimental vdelivermail filter
# WITH_QMAIL_EXT - enables qmail-like user-* address extesions processing
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
# VCHKPW_GID	- the group ID of the new vchkpw group (89)
# VPOPMAIL_UID	- the user ID of the new vpopmail user (89)
# WITH_MYSQL_SERVER - the hostname of the MySQL server (localhost)
# WITH_MYSQL_USER - the username for connecting to the MySQL server (root)
# WITH_MYSQL_PASSWD - the password for connecting to the MySQL server (secret)
# WITH_MYSQL_DB - the name of the MySQL database to use (vpopmail)
# The server, user and password variables may be defined separately
# for read and update access, allowing you to set up a less-priviledged
# MySQL connection account with read-only access, and another one which
# is used for administrative purposes:
# WITH_MYSQL_READ_SERVER, WITH_MYSQL_READ_USER, WITH_MYSQL_READ_PASSWD
# WITH_MYSQL_UPDATE_SERVER, WITH_MYSQL_UPDATE_USER, WITH_MYSQL_UPDATE_PASSWD
# Those variables, if defined, override WITH_MYSQL_{SERVER,USER,PASSWD}
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

CONFIGURE_ARGS+=	--enable-defaultquota=${HARDQUOTA} \
			--enable-logging=${LOGLEVEL}

.if defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd=y
.endif

.if defined(WITH_MD5_PASSWORDS)
CONFIGURE_ARGS+=	--enable-md5-passwords=y
.endif

.if defined(WITH_APOP)
CONFIGURE_ARGS+=	--enable-apop=y \
			--enable-apop-file=${APOPFILE}
.else
CONFIGURE_ARGS+=	--enable-apop=n
.endif

.if defined(WITH_SQWEBMAIL)
CONFIGURE_ARGS+=	--enable-sqwebmail-pass=y
.endif

.if !defined(WITHOUT_ROAMING)
CONFIGURE_ARGS+=	--enable-roaming-users=y \
			--enable-relay-clear-minutes=${RELAYCLEAR}
.endif

.if !defined(WITH_CLEAR_PASSWD)
CONFIGURE_ARGS+=	--enable-clear-passwd=n
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--enable-mysql=y \
			--enable-sqlincdir=${LOCALBASE}/include/mysql \
			--enable-sqllibdir=${LOCALBASE}/lib/mysql
.if defined(WITH_MYSQL_LARGE_SITE)
CONFIGURE_ARGS+=	--enable-large-site=y
.endif

.if defined(WITH_MYSQL_SERVER)
WITH_MYSQL_READ_SERVER?=	${WITH_MYSQL_SERVER}
WITH_MYSQL_UPDATE_SERVER?=	${WITH_MYSQL_SERVER}
.endif
.if defined(WITH_MYSQL_USER)
WITH_MYSQL_READ_USER?=	${WITH_MYSQL_USER}
WITH_MYSQL_UPDATE_USER?=	${WITH_MYSQL_USER}
.endif
.if defined(WITH_MYSQL_PASSWD)
WITH_MYSQL_READ_PASSWD?=	${WITH_MYSQL_PASSWD}
WITH_MYSQL_UPDATE_PASSWD?=	${WITH_MYSQL_PASSWD}
.endif
.endif

.if defined(DEFAULT_DOMAIN)
CONFIGURE_ARGS+=	--enable-default-domain=${DEFAULT_DOMAIN}
.endif

.if defined(WITH_IP_ALIAS)
CONFIGURE_ARGS+=	--enable-ip-alias-domains=y
.endif

.if defined(WITH_DELIVER_FILTER)
CONFIGURE_ARGS+=	--enable-deliver-filter=y
.endif

.if defined(WITH_QMAIL_EXT)
CONFIGURE_ARGS+=	--enable-qmail-ext=y
.endif

# autoconf and automake can remove our patches to the configure scripts.

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX}/vpopmail ${PERL5} ${PKGINSTALL}
.if defined(WITH_MYSQL)
.if defined(WITH_MYSQL_UPDATE_SERVER)
	${REINPLACE_CMD} -E "s/(#define MYSQL_UPDATE_SERVER.*)localhost(.*)/\1${WITH_MYSQL_UPDATE_SERVER}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_SERVER)
	${REINPLACE_CMD} -E "s/(#define MYSQL_READ_SERVER.*)localhost(.*)/\1${WITH_MYSQL_READ_SERVER}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_UPDATE_USER)
	${REINPLACE_CMD} -E "s/(#define MYSQL_UPDATE_USER.*)root(.*)/\1${WITH_MYSQL_UPDATE_USER}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_USER)
	${REINPLACE_CMD} -E "s/(#define MYSQL_READ_USER.*)root(.*)/\1${WITH_MYSQL_READ_USER}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_UPDATE_PASSWD)
	${REINPLACE_CMD} -E "s/(#define MYSQL_UPDATE_PASSWD.*)secret(.*)/\1${WITH_MYSQL_UPDATE_PASSWD}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_PASSWD)
	${REINPLACE_CMD} -E "s/(#define MYSQL_READ_PASSWD.*)secret(.*)/\1${WITH_MYSQL_READ_PASSWD}\2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_DB)
	${REINPLACE_CMD} -E "s/(#define MYSQL_DATABASE.*)vpopmail(.*)/\1${WITH_MYSQL_DB}\2/" ${WRKSRC}/vmysql.h
.endif
.endif
	${MKDIR} ${VCFGDIR}

post-install:
	${CHMOD} o-rwx ${PREFIX}/vpopmail/bin ${PREFIX}/vpopmail/lib
	${MKDIR} ${PREFIX}/vpopmail/etc
	if [ ! -f "${PREFIX}/vpopmail/etc/tcp.smtp" ]; then \
		if [ -f "${VCFGDIR}/tcp.smtp" ]; then \
			${INSTALL_DATA} ${VCFGDIR}/tcp.smtp ${PREFIX}/vpopmail/etc/; \
		else \
			${TOUCH} ${PREFIX}/vpopmail/etc/tcp.smtp; \
		fi; \
	fi
	${INSTALL_DATA} ${VCFGDIR}/inc_deps ${VCFGDIR}/lib_deps ${PREFIX}/vpopmail/etc/

.include <bsd.port.mk>
