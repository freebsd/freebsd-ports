# ex:ts=8
# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
DISTVERSION=	1.0.beta7
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/

MAINTAINER=	robin@isometry.net
COMMENT=	Secure and compact IMAP and POP3 servers

USE_ICONV=	yes
USE_RC_SUBR=	dovecot.sh

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-shadow --localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PKGMESSAGE=	${WRKDIR}/pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	USE-WIKI-INSTEAD \
		auth-protocol.txt auth.txt configuration.txt design.txt \
		index.txt mail-storages.txt multiaccess.txt nfs.txt \
		securecoding.txt variables.txt
.else
CONFIGURE_ARGS+=	--without-docs
.endif

OPTIONS=	KQUEUE		"kqueue(2) support"	off  \
		SASL2		"SASL2 support"		off \
		GSSAPI		"GSSAPI support"	off \
		VPOPMAIL	"VPopMail support"	off \
		LDAP		"OpenLDAP support"	off \
		PGSQL		"PostgreSQL support"	off \
		MYSQL		"MySQL support"		off \
		SQLITE		"SQLite support"	off

.include <bsd.port.pre.mk>

## kqueue(2) support
#
.if defined(WITH_KQUEUE) 
CONFIGURE_ARGS+=	--with-ioloop=kqueue --with-notify=kqueue
.endif

## SASL2 support
#
.if defined(WITH_SASL2)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl2
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

post-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DATADIR}
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
