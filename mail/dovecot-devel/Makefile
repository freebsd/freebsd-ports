# ex:ts=8
# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
DISTVERSION=	1.1.0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/1.1/

MAINTAINER=	yds@coolrat.org
COMMENT=	Secure and compact IMAP and POP3 servers

USE_ICONV=	yes
USE_RC_SUBR=	dovecot.sh

DEPRECATED=	Please use mail/dovecot instead

CONFLICTS?=	${PORTNAME}-1.[02-9].*
NO_LATEST_LINK=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-shadow --localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	${PREFIX}/lib/dovecot \
		${PREFIX}/lib/dovecot/imap \
		${PREFIX}/lib/dovecot/pop3 \
		${PREFIX}/lib/dovecot/lda

.if !defined(NOPORTDOCS)
PORTDOCS=	*.txt wiki
.else
CONFIGURE_ARGS+=	--without-docs
.endif

DOVECOT_UID?=	143
DOVECOT_GID?=	143
SCRIPT_ENV+=	DOVECOT_UID=${DOVECOT_UID} \
		DOVECOT_GID=${DOVECOT_GID}

OPTIONS=	KQUEUE		"kqueue(2) support"	on  \
		SSL		"SSL support"		on  \
		IPV6		"IPv6 support"		on  \
		POP3		"POP3 support"		on  \
		LDA		"LDA support"		on  \
		GSSAPI		"GSSAPI support"	off \
		VPOPMAIL	"VPopMail support"	off \
		LDAP		"OpenLDAP support"	off \
		PGSQL		"PostgreSQL support"	off \
		MYSQL		"MySQL support"		off \
		SQLITE		"SQLite support"	off

.include <bsd.port.pre.mk>

## kqueue(2) support
#
.if !defined(WITHOUT_KQUEUE)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
.endif

## SSL support
#
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-ssl
.endif

## IPv6 support
#
.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

## POP3 support
#
.if defined(WITHOUT_POP3)
CONFIGURE_ARGS+=	--without-pop3d
PROTOCOLS=		imap
PLIST_SUB+=		POP3="@comment "
.else
PROTOCOLS=		imap pop3
PLIST_SUB+=		POP3=""
.endif

## LDA support
#
.if defined(WITHOUT_LDA)
CONFIGURE_ARGS+=	--without-deliver
PLIST_SUB+=		LDA="@comment "
.else
PLIST_SUB+=		LDA=""
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

## OpenLDAP Support
#
.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

## PostgreSQL Support
#
.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql
.endif

## MySQL Support
#
.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
.endif

## SQLite Support
#
.if defined(WITH_SQLITE)
USE_SQLITE=		3
CONFIGURE_ARGS+=	--with-sqlite
.endif

post-patch:
.if defined(WITH_GSSAPI)
	@${REINPLACE_CMD} -e 's,<gssapi/gssapi\.h>,<gssapi.h>,' \
		${WRKSRC}/src/auth/mech-gssapi.c \
		${WRKSRC}/configure
.endif

post-build:
	@${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%PROTOCOLS%%,${PROTOCOLS},g' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DATADIR}
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
