# New ports collection makefile for:	dovecot2
# Date created:		2010/09/21
# Whom:			Nagy, Attila <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	2.1.8
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${PORTVERSION:R}/

MAINTAINER=	bra@fsn.hu
COMMENT=	Secure and compact IMAP and POP3 servers

LATEST_LINK=	dovecot2
CONFLICTS=	dovecot-1.[0-9]*

######################################################################
# Anytime PORTVERSION changes please bump PORTREVISION of            #
# mail/dovecot2-pigeonhole and also mail/dovecot2-antispam-plugin.   #
# Please see ports/135311 and ports/146029 for an explanation.       #
#                                                                    #
# Please be careful when updating this port as changes to this port  #
# can break mail/dovecot2-pigeonhole. In order to ensure the least   #
# amount of breakage possible please consult the maintainer of that  #
# port before updating this one.                                     #
######################################################################

USE_ICONV=	yes
USE_RC_SUBR=	dovecot
MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-statedir=/var/db/dovecot \
		--without-shadow
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot

USERS=		${PORTNAME} dovenull
GROUPS=		${USERS}

PROTOCOLS=	imap pop3

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

OPTIONS_DEFINE=	KQUEUE SSL GSSAPI VPOPMAIL LDAP PGSQL MYSQL SQLITE SOLR DOCS \
		EXAMPLES LIBWRAP
OPTIONS_DEFAULT=	KQUEUE SSL

KQUEUE_DESC=	kqueue(2) support
VPOPMAIL_DESC=	vpopmail support
SOLR_DESC=	Solr FTS support

.include <bsd.port.pre.mk>

# sed script for dovecot.conf
REINPLACE=	s!%%PROTOCOLS%%!${PROTOCOLS}!g;\
		s!/usr/!${PREFIX}/!g;\
		s!=/usr!=${PREFIX}!g;\
		s!=/etc !=${PREFIX}/etc !g;\
		s!/etc/dovecot!${PREFIX}&!g;\
		s![[:<:]]doc/(dovecot-[^-]+)-example.conf[[:>:]]!${EXAMPLESDIR}/\1.conf!g;\
		s!\#sendmail_path = /usr/.*!sendmail_path = /usr/sbin/sendmail!g;

.if ${PORT_OPTIONS:MDOCS}
DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*
PLIST_SUB+=	PORT=""
.else
CONFIGURE_ARGS+=	--without-docs
PLIST_SUB+=	PORT="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

## kqueue(2) support
#
.if ${PORT_OPTIONS:MKQUEUE)
CONFIGURE_ARGS+=--with-ioloop=kqueue
.endif

## SSL support
#
.if ${PORT_OPTIONS:MSSL}
PROTOCOLS+=	imaps pop3s
.else
CONFIGURE_ARGS+=--without-ssl
.endif

## GSSAPI support
#
.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--with-gssapi
.else
CONFIGURE_ARGS+=--without-gssapi
.endif

## VPopMail Support
#
.if ${PORT_OPTIONS:MVPOPMAIL}
BUILD_DEPENDS+=	${LOCALBASE}/vpopmail/bin/vchkpw:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=--with-vpopmail
.else
CONFIGURE_ARGS+=--without-vpopmail
.endif

## OpenLDAP Support
#
.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap
PLIST_SUB+=	LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--without-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

## PostgreSQL Support
#
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql
PLIST_SUB+=	SQL=""
_REQUIRE+=	postgresql
.else
CONFIGURE_ARGS+=--without-pgsql
PLIST_SUB+=	SQL="@comment "
.endif

## MySQL Support
#
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
PLIST_SUB+=	SQL=""
_REQUIRE+=	mysql
.else
CONFIGURE_ARGS+=--without-mysql
PLIST_SUB+=	SQL="@comment "
.endif

## SQLite Support
#
.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
CONFIGURE_ARGS+=--with-sqlite
PLIST_SUB+=	SQL=""
.else
CONFIGURE_ARGS+=--without-sqlite
PLIST_SUB+=	SQL="@comment "
.endif

## SOLR support
#
.if ${PORT_OPTIONS:MSOLR}
CONFIGURE_ARGS+=--with-solr
BUILD_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
PLIST_SUB+=	SOLR=""
.else
CONFIGURE_ARGS+=--without-solr
PLIST_SUB+=	SOLR="@comment "
.endif

## libwrap support
#
.if ${PORT_OPTIONS:MLIBWRAP}
CONFIGURE_ARGS+=--with-libwrap
PLIST_SUB+=	LIBWRAP=""
.else
CONFIGURE_ARGS+=--without-libwrap
PLIST_SUB+=	LIBWRAP="@comment "
.endif

SUB_LIST=	REQUIRE="${_REQUIRE}"
SUB_FILES=	pkg-deinstall pkg-message

MAN1=		deliver.1 \
		doveadm-altmove.1 \
		doveadm-auth.1 \
		doveadm-config.1 \
		doveadm-director.1 \
		doveadm-dump.1 \
		doveadm-expunge.1 \
		doveadm-fetch.1 \
		doveadm-force-resync.1 \
		doveadm-help.1 \
		doveadm-import.1 \
		doveadm-index.1 \
		doveadm-instance.1 \
		doveadm-kick.1 \
		doveadm-log.1 \
		doveadm-mailbox.1 \
		doveadm-mount.1 \
		doveadm-move.1 \
		doveadm-penalty.1 \
		doveadm-purge.1 \
		doveadm-pw.1 \
		doveadm-quota.1 \
		doveadm-reload.1 \
		doveadm-search.1 \
		doveadm-stop.1 \
		doveadm-user.1 \
		doveadm-who.1 \
		doveadm.1 \
		doveconf.1 \
		dovecot-lda.1 \
		dovecot.1 \
		dsync.1
MAN7=		doveadm-search-query.7

post-patch:
	@${REINPLACE_CMD} -E -e '${REINPLACE}' \
		${WRKSRC}/doc/example-config/dovecot.conf
	@${REINPLACE_CMD} -E -e'\
		s!-example\.conf[[:>:]]!.conf!g;\
		s!^(confdir[[:space:]]+=[[:space:]]+)\$$\(sysconfdir\)!\1${EXAMPLESDIR}!g;\
		' ${WRKSRC}/*/Makefile.in ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_SCRIPT} dovecot-openssl.cnf mkcert.sh ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
