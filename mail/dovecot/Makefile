# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	1.2.17
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${DOVECOTVERSION}/ \
		http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/

MAINTAINER=	yds@CoolRat.org
COMMENT=	Secure and compact IMAP and POP3 servers

CONFLICTS=	dovecot-2.*

DOVECOTVERSION=	1.2

######################################################################
# Anytime PORTVERSION changes please bump PORTREVISIONs of           #
# mail/dovecot-antispam, mail/dovecot-managesieve and                #
# mail/dovecot-sieve. Please see ports/135311 and ports/146029 for   #
# an explanation.                                                    #
#                                                                    #
# Please be careful when updating this port as changes to this port  #
# can break mail/dovecot-sieve and mail/dovecot-managesieve. In      #
# order to ensure the least amount of breakage possible please       #
# consult the maintainer of those ports before updating this one.    #
######################################################################

USE_ICONV=	yes
USE_RC_SUBR=	dovecot

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--localstatedir=/var \
			--with-statedir=/var/db/dovecot \
			--without-shadow
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot \
		${PREFIX}/lib/dovecot/imap \
		${PREFIX}/lib/dovecot/pop3 \
		${PREFIX}/lib/dovecot/lda

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docs
.else
DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*.txt wiki ${DOCS}
.endif

DOVECOT_UID?=	143
DOVECOT_GID?=	143

PROTOCOLS=	imap pop3

OPTIONS=	KQUEUE		"kqueue(2) support"	on  \
		SSL		"SSL support"		on  \
		MANAGESIEVE	"ManageSieve support"	on  \
		GSSAPI		"GSSAPI support"	off \
		VPOPMAIL	"VPopMail support"	off \
		BDB		"BerkleyDB support"	off \
		LDAP		"OpenLDAP support"	off \
		PGSQL		"PostgreSQL support"	off \
		MYSQL		"MySQL support"		off \
		SQLITE		"SQLite support"	off

.include <bsd.port.pre.mk>

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

# sed script for dovecot.conf
REINPLACE=	s!%%PROTOCOLS%%!${PROTOCOLS}!g;\
		s!/usr/!${PREFIX}/!g;\
		s!=/usr!=${PREFIX}!g;\
		s!=/etc !=${PREFIX}/etc !g;\
		s!/etc/dovecot!${PREFIX}&!g;\
		s![[:<:]]doc/(dovecot-[^-]+)-example.conf[[:>:]]!${EXAMPLESDIR}/\1.conf!g;\
		s!\#sendmail_path = /usr/.*!sendmail_path = /usr/sbin/sendmail!g;

## kqueue(2) support
#
.if !defined(WITHOUT_KQUEUE)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
.endif

## SSL support
#
.if defined(WITH_SSL)
PROTOCOLS+=		imaps pop3s
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

## ManageSieve support
#
.if defined(WITH_MANAGESIEVE)
MANAGESIEVEVERSION!=	${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V PORTVERSION
PATCH_SITES!=		${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V MASTER_SITES
PATCHFILES+=		dovecot-${PORTVERSION}-managesieve-${MANAGESIEVEVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1
PROTOCOLS+=		managesieve
DOCS+=			README.managesieve
.endif

## GSSAPI support
#
.if defined(WITH_GSSAPI)
CONFIGURE_ARGS+=	--with-gssapi
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

## VPopMail Support
#
.if defined(WITH_VPOPMAIL)
VPOPMAIL=		${LOCALBASE}/vpopmail/bin/vchkpw
BUILD_DEPENDS+=		${VPOPMAIL}:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=	--with-vpopmail
.else
CONFIGURE_ARGS+=	--without-vpopmail
.endif

## BDB Support
#
.if defined(WITH_BDB)
USE_BDB=		42+
CONFIGURE_ARGS+=	--with-db
CFLAGS+=		-I${BDB_INCLUDE_DIR} -L${BDB_LIB_DIR}
PLIST_SUB+=		BDB=""
REINPLACE+=		s!^\#(dict_db_config)!\1!;
.else
PLIST_SUB+=		BDB="@comment "
.endif

## OpenLDAP Support
#
.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
PLIST_SUB+=		LDAP=""
_REQUIRE+=		slapd
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

## PostgreSQL Support
#
.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=		SQL=""
_REQUIRE+=		postgresql
.else
CONFIGURE_ARGS+=	--without-pgsql
PLIST_SUB+=		SQL="@comment "
.endif

## MySQL Support
#
.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		SQL=""
_REQUIRE+=		mysql
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		SQL="@comment "
.endif

## SQLite Support
#
.if defined(WITH_SQLITE)
USE_SQLITE=		3
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=		SQL=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQL="@comment "
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}" DOVECOT_UID=${DOVECOT_UID} DOVECOT_GID=${DOVECOT_GID}
SUB_FILES+=		pkg-install pkg-deinstall pkg-message

post-patch:
	@${REINPLACE_CMD} -E -e '${REINPLACE}' \
		${WRKSRC}/dovecot-example.conf
	@${REINPLACE_CMD} -E -e'\
		s!-example\.conf[[:>:]]!.conf!g;\
		s!^(confdir[[:space:]]+=[[:space:]]+)\$$\(sysconfdir\)!\1${EXAMPLESDIR}!g;\
		' ${WRKSRC}/*/Makefile.in ${WRKSRC}/Makefile.in
	@${LN} -f ${WRKSRC}/dovecot-example.conf		${WRKSRC}/dovecot.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-db-example.conf		${WRKSRC}/doc/dovecot-db.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-dict-sql-example.conf	${WRKSRC}/doc/dovecot-dict-sql.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-ldap-example.conf	${WRKSRC}/doc/dovecot-ldap.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-sql-example.conf	${WRKSRC}/doc/dovecot-sql.conf

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/dovecot.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-db.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-dict-sql.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-ldap.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-sql.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EXAMPLESDIR}
	@${GREP} '^@exec ' ${TMPPLIST} \
		| ${SED} -e 's:^@exec ::; s:%D:${PREFIX}:g;' \
		> ${WRKDIR}/.PLIST.exec \
		&& ${SH} ${WRKDIR}/.PLIST.exec
.if !defined(NOPORTDOCS)
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
