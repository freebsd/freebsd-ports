# New ports collection makefile for:	jabberd
# Date created:				29 December 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jabberd
PORTVERSION=	2.0.5
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/jabberd2/
DISTNAME=	${PORTNAME}-2.0s5
DIST_SUBDIR=	jabber

MAINTAINER=	kirk@strauser.com
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	idn.16:${PORTSDIR}/devel/libidn

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_RC_SUBR=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-ssl \
		--with-extra-include-path=${LOCALBASE}/include${EIP} \
		--with-extra-library-path=${LOCALBASE}/lib${ELP} \
		--enable-fs

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_POSTGRESQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--enable-pgsql
.else
CONFIGURE_ARGS+=--disable-pgsql
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

MAN8=		c2s.8 jabberd.8 resolver.8 router.8 s2s.8 sm.8

pre-everything::
	@${ECHO}
	@${ECHO} "You can build Jabber with the following options:"
	@${ECHO} "WITH_POSTGRESQL		use PostgreSQL for storage and authentication"
	@${ECHO} "WITH_BDB		use Berkeley DB for storage and authentication"
	@${ECHO} "WITH_MYSQL		use MySQL for storage and authentication"
	@${ECHO} "WITH_LDAP		use LDAP for authentication"
	@${ECHO} "WITH_PAM		use PAM for authentication"
	@${ECHO}

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/jabberd.sh > ${WRKDIR}/jabberd.sh

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${ECHO} "Installing ${PREFIX}/etc/rc.d/jabberd.sh startup file."
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/jabberd.sh ${PREFIX}/etc/rc.d/jabberd.sh
	@${CHOWN} -R jabber:jabber ${PREFIX}/etc/jabberd
	@${FIND} ${PREFIX}/etc/jabberd -type d | ${XARGS} ${CHMOD} 750
	@${FIND} ${PREFIX}/etc/jabberd -type f | ${XARGS} ${CHMOD} 660
	@${MKDIR} ${PREFIX}/share/jabberd
	@${INSTALL_DATA} ${WRKSRC}/tools/db-setup.mysql ${PREFIX}/share/jabberd
	@${INSTALL_DATA} ${WRKSRC}/tools/db-setup.pgsql ${PREFIX}/share/jabberd

.include <bsd.port.mk>
