# ex:ts=8
# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
DISTVERSION=	1.0.alpha3
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/

MAINTAINER=	robin@isometry.net
COMMENT=	Secure and compact IMAP and POP3 servers

USE_ICONV=	yes
USE_RC_SUBR=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-shadow --with-pam \
		--localstatedir=/var --with-ssl=openssl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		USE-WIKI-INSTEAD \
		auth-protocol.txt auth.txt configuration.txt design.txt \
		index.txt mail-storages.txt mkcert.sh multiaccess.txt \
		nfs.txt securecoding.txt variables.txt \
		dovecot-ldap.conf dovecot-sql.conf dovecot-openssl.cnf

OPTIONS=	SASL2		"SASL2 support"		off \
		VPOPMAIL	"VPopMail support"	off \
		LDAP		"OpenLDAP support"	off \
		PGSQL		"PostgreSQL support"	off \
		MYSQL		"MySQL support"		off

.include <bsd.port.pre.mk>

## SASL2 support
#
# SASL provides authentication support to
# session-based protocols. This is can be
# used by dovecot for authentication sources.
#
.if defined(WITH_SASL2)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl2
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

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/dovecot-example.conf >${WRKDIR}/dovecot.conf.sample
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		${FILESDIR}/dovecot.sh >${WRKDIR}/dovecot.sh

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/libexec/dovecot
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/auth/checkpassword-reply \
		${WRKSRC}/src/auth/dovecot-auth \
		${WRKSRC}/src/deliver/deliver \
		${WRKSRC}/src/imap/imap \
		${WRKSRC}/src/imap-login/imap-login \
		${WRKSRC}/src/pop3/pop3 \
		${WRKSRC}/src/pop3-login/pop3-login \
		${WRKSRC}/src/util/rawlog \
			${PREFIX}/libexec/dovecot/
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/master/dovecot \
		${WRKSRC}/src/util/dovecotpw \
			${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKDIR}/dovecot.conf.sample ${PREFIX}/etc/
	${INSTALL_SCRIPT} ${WRKDIR}/dovecot.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
