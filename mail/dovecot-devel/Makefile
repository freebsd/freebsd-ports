# ex:ts=8
# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	0.99.10.4
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/

MAINTAINER=	robin@isometry.net
COMMENT=	Secure and compact IMAP and POP3 servers

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-shadow --enable-ipv6 \
		--localstatedir=/var --with-ssl=openssl \
		--with-ssldir=/var/dovecot/ssl --with-pop3d \
		--with-pam
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		auth.txt configuration.txt design.txt \
		index.txt mail-storages.txt mkcert.sh multiaccess.txt \
		nfs.txt dovecot-ldap.conf dovecot-pgsql.conf \
		dovecot-openssl.cnf securecoding.txt

.include <bsd.port.pre.mk>

## SASL2 support
OPTIONS+=	SASL2 "SASL2 support" off
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
OPTIONS+=	VPOPMAIL  "VPopMail support" off
#
# vpopmail provides easy authentication and
# multi-domain features. It was originally
# created for use with Qmail.
#
.if defined(WITH_VPOPMAIL)
VPOPMAIL=		${LOCALBASE}/vpopmail/bin/vchkpw
BUILD_DEPENDS+=		${VPOPMAIL}:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=	--with-vpopmail
.endif

## OpenLDAP Support
OPTIONS+=	LDAP  "OpenLDAP support" off
#
# LDAP is the light-weight directory access
# protocol and can be used by Dovecot for its
# user database.
#
.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

## PostgreSQL Support
OPTIONS+=	PGSQL  "PostgreSQL support" off
#
# PostgreSQL is a powerful SQL database that
# can be used to store user tables.
#
.if defined(WITH_PGSQL)
LIB_DEPENDS+=		pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql
.endif

.if ${OSVERSION} >= 500038
RC_SUBR?=	/etc/rc.subr
.else
USE_RC_SUBR=	yes
.endif

pre-build:
	@${REINPLACE_CMD} -e 's,%%SSLDIR%%,/var/dovecot/ssl,' \
		${WRKSRC}/doc/mkcert.sh \
		${WRKSRC}/dovecot-example.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/dovecot-example.conf

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		${FILESDIR}/dovecot.sh >${WRKDIR}/dovecot.sh

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/libexec/dovecot
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/imap/imap \
		${WRKSRC}/src/pop3/pop3 \
		${WRKSRC}/src/auth/dovecot-auth \
		${WRKSRC}/src/imap-login/imap-login \
		${WRKSRC}/src/pop3-login/pop3-login \
			${PREFIX}/libexec/dovecot/
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf ${PREFIX}/etc/
	${INSTALL_PROGRAM} ${WRKSRC}/src/master/dovecot ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKDIR}/dovecot.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
