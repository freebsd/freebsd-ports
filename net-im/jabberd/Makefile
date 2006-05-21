# New ports collection makefile for:	jabberd
# Date created:				29 December 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jabberd
PORTVERSION=	2.0.11
CATEGORIES=	net-im
MASTER_SITES=	http://files.jabberstudio.org/jabberd2/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}s${PORTVERSION:E}
DIST_SUBDIR=	jabber

MAINTAINER=	kirk@strauser.com
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn

BROKEN=		Unfetchable

OPTIONS=	POSTGRESQL "Use PostgreSQL for storage and authentication" off \
		MYSQL "Use MySQL for storage and authentication" off \
		LDAP "Use LDAP for authentication" off \
		BDB "Use BDB for storage and authentication" off \
		SQLITE "Use SQLITE3 for storage" off \
		PAM "Use PAM for authentication" off \
		PIPE "Enable pipe auth/reg support" off \
		AVATAR "Enable avatar support in vCard" off \
		DEBUG "Compile with debug information" on

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_RC_SUBR=	jabberd.sh
CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-ssl \
		--with-extra-include-path=${LOCALBASE}/include${EIP} \
		--with-extra-library-path=${LOCALBASE}/lib${ELP} \
		--enable-fs

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-pgsql
.else
CONFIGURE_ARGS+=--disable-pgsql
.endif

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=--enable-sqlite
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=--disable-sqlite
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
EIP+=:${LOCALBASE}/include/mysql
ELP+=:${LOCALBASE}/lib/mysql
.else
CONFIGURE_ARGS+=--disable-mysql
.endif

.if defined(WITH_BDB)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--enable-db
CONFIGURE_ARGS+=--oldincludedir=/nonexistant
EIP+=:${LOCALBASE}/include/db41
.else
CONFIGURE_ARGS+=--disable-db
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-ldap
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=--enable-pam
.else
CONFIGURE_ARGS+=--disable-pam
.endif

.if defined(WITH_PIPE)
CONFIGURE_ARGS+=--enable-pipe
.endif

.if defined(WITH_AVATAR)
PATCH_SITES+=	http://www.deepdarc.com/
PATCHFILES+=	vcard-avatar.diff
.endif

MAN8=		c2s.8 jabberd.8 resolver.8 router.8 s2s.8 sm.8

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${CHOWN} -R jabber:jabber ${PREFIX}/etc/jabberd
	@${FIND} ${PREFIX}/etc/jabberd -type d | ${XARGS} ${CHMOD} 750
	@${FIND} ${PREFIX}/etc/jabberd -type f | ${XARGS} ${CHMOD} 660
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/db-setup.mysql ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/db-setup.pgsql ${DATADIR}

.include <bsd.port.post.mk>
