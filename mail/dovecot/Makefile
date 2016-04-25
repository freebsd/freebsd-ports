# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	dovecot
PORTVERSION=	1.2.17
PORTREVISION=	6
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${PORTVERSION:R}/ \
		http://www.rename-it.nl/dovecot/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure and compact IMAP and POP3 servers

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual

CONFLICTS=	dovecot2-2.[0-9].*

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

USES=		cpe iconv libtool:keepla
USE_RC_SUBR=	dovecot
USE_OPENSSL=	yes

PORTSCOUT=	limit:^1\.2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-statedir=/var/db/dovecot \
		--without-shadow

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	${PREFIX}/lib/dovecot \
		${PREFIX}/lib/dovecot/imap \
		${PREFIX}/lib/dovecot/pop3 \
		${PREFIX}/lib/dovecot/lda

USERS=		dovecot
GROUPS=		${USERS}

PROTOCOLS=	imap pop3

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

OPTIONS_DEFINE=	KQUEUE SSL MANAGESIEVE GSSAPI VPOPMAIL BDB LDAP PGSQL MYSQL SQLITE DOCS
OPTIONS_DEFAULT=	KQUEUE SSL MANAGESIEVE
KQUEUE_DESC=		kqueue(2) support
MANAGESIEVE_DESC=	ManageSieve support
VPOPMAIL_DESC=		VPopMail support

OPTIONS_SUB=		yes
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR} -L${BDB_LIB_DIR}
BDB_CONFIGURE_WITH=	db
BDB_USE=		BDB=48+
DOCS_CONFIGURE_WITH=	docs
GSSAPI_CONFIGURE_WITH=	gssapi
GSSAPI_LDFLAGS=		-lgssapi_krb5
KQUEUE_CONFIGURE_ON=	--with-ioloop=kqueue
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		MYSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USES=		pgsql
SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_USES=		sqlite:3
SSL_CONFIGURE_OFF=	--without-ssl
SSL_CONFIGURE_ON=	--with-ssl=openssl
VPOPMAIL_BUILD_DEPENDS=	${LOCALBASE}/vpopmail/bin/vchkpw:mail/vpopmail
VPOPMAIL_CONFIGURE_WITH=vpopmail

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not build on arm
.endif

DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*

.if ${PORT_OPTIONS:MSSL}
PROTOCOLS+=	imaps pop3s
.endif

.if ${PORT_OPTIONS:MLDAP}
_REQUIRE+=	slapd
.endif

.if ${PORT_OPTIONS:MPGSQL}
_REQUIRE+=	postgresql
.endif

.if ${PORT_OPTIONS:MMYSQL}
_REQUIRE+=	mysql
.endif

SUB_LIST+=	REQUIRE="${_REQUIRE}"
SUB_FILES+=	pkg-deinstall pkg-message

# sed script for dovecot.conf
REINPLACE=	s!%%PROTOCOLS%%!${PROTOCOLS}!g;\
		s!/usr/!${PREFIX}/!g;\
		s!=/usr!=${PREFIX}!g;\
		s!=/etc !=${PREFIX}/etc !g;\
		s!/etc/dovecot!${PREFIX}&!g;\
		s![[:<:]]doc/(dovecot-[^-]+)-example.conf[[:>:]]!${EXAMPLESDIR}/\1.conf!g;\
		s!\#sendmail_path = /usr/.*!sendmail_path = /usr/sbin/sendmail!g;

.if ${PORT_OPTIONS:MBDB}
REINPLACE+=	s!^\#(dict_db_config)!\1!;
.endif

.if ${PORT_OPTIONS:MMANAGESIEVE}
MANAGESIEVEVERSION!=	${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V PORTVERSION
PATCH_SITES!=		${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V MASTER_SITES
PATCHFILES+=		dovecot-${PORTVERSION}-managesieve-${MANAGESIEVEVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1
PROTOCOLS+=		managesieve
DOCS+=			README.managesieve
.endif

.if ${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MSQLITE}
PLIST_SUB+=	SQL=""
.else
PLIST_SUB+=	SQL="@comment "
.endif

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

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/ -name \*.so | ${XARGS} strip
	${INSTALL_DATA} ${WRKSRC}/dovecot.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-db.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-dict-sql.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-ldap.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-sql.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${STAGEDIR}${EXAMPLESDIR}

.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
