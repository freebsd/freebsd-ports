# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	0.99.10.2
CATEGORIES=	mail ipv6
MASTER_SITES=	http://dovecot.procontrol.fi/

MAINTAINER=	ports@FreeBSD.org
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

.include <bsd.port.pre.mk>

#
# Feature Autodetection
#
.if exists(${LOCALBASE}/lib/libsasl.so.2)
WITH_SASL2=	yes
.endif

.if exists(${LOCALBASE}/vpopmail/bin/vckpw)
WITH_VPOPMAIL=	yes
.endif

.if exists(${LOCALBASE}/lib/libldap.so.2)
WITH_LDAP2=	yes
.endif

.if exists(${LOCALBASE}/lib/libpq.so.3)
WITH_PGSQL=	yes
.endif

#
# SASL2 support
#
# SASL provides authentication support to
# session-based protocols. This is can be
# used by dovecot for authentication sources.
#
.if WITH_SASL2
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.endif

#
# VPopMail Support
#
# vpopmail provides easy authentication and
# multi-domain features. It was originally
# created for use with Qmail.
#
.if WITH_VPOPMAIL
VPOPMAIL=	${LOCALBASE}/vpopmail/bin/vchkpw
BUILD_DEPENDS+=	${VPOPMAIL}:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=	--with-vpopmail
.endif

#
# OpenLDAP Support
#
# LDAP is the light-weight directory access
# protocol and can be used by Dovecot for its
# user database.
#
.if WITH_LDAP2
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap21-client
CONFIGURE_ARGS+=	--with-ldap
.endif

#
# PostgreSQL Support
#
# PostgreSQL is a powerful SQL database which
# can be used to store user tables.
#
.if WITH_PGSQL
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-pgsql
.endif

pre-everything::
	@${ECHO_MSG} "==>  Dovecot Options"
	@${ECHO_MSG} "==>   See the Makefile for descriptions."
	@${ECHO_MSG} "==> ------------------------------------------"
	@${ECHO_MSG} "==>  o SASL2 Support         + WITH_SASL2"
	@${ECHO_MSG} "==>  o VPoPMail Support      + WITH_VPOPMAIL"
	@${ECHO_MSG} "==>  o OpenLDAP2 Support     + WITH_LDAP2"
	@${ECHO_MSG} "==>  o PostgreSQL Support    + WITH_PGSQL"
	@${ECHO_MSG} "==> ------------------------------------------"

pre-build:
	@${REINPLACE_CMD} -e 's,%%SSLDIR%%,/var/dovecot/ssl,' \
		${WRKSRC}/doc/mkcert.sh \
		${WRKSRC}/dovecot-example.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

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

post-install:
	@${MKDIR} /var/dovecot
	@${MKDIR} /var/dovecot/ssl
	@${MKDIR} /var/dovecot/ssl/certs
	@${MKDIR} /var/dovecot/ssl/private
	@${MKDIR} /var/dovecot/auth
	@${CHOWN} -R dovecot:dovecot /var/dovecot
	@${MKDIR} /var/dovecot/login
	@${CHOWN} root:dovecot /var/dovecot/login
	@${MKDIR} /var/run/dovecot
	@${CHMOD} 0700 /var/run/dovecot
	@${CHOWN} root:dovecot /var/run/dovecot
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dovecot.sh.sample \
		${PREFIX}/etc/rc.d/dovecot.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} \
		${WRKSRC}/doc/auth.txt \
		${WRKSRC}/doc/design.txt \
		${WRKSRC}/doc/index.txt \
		${WRKSRC}/doc/multiaccess.txt \
		${WRKSRC}/doc/nfs.txt \
		${WRKSRC}/doc/configuration.txt \
		${WRKSRC}/doc/mail-storages.txt \
		${WRKSRC}/doc/dovecot-ldap.conf \
		${WRKSRC}/doc/dovecot-pgsql.conf \
		${WRKSRC}/doc/dovecot-openssl.cnf \
		${WRKSRC}/doc/mkcert.sh \
		${FILESDIR}/README.FreeBSD \
			${DOCSDIR}
.endif
	@${CP} ${PKGMESSAGE} ${WRKDIR}/pkg-message
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKDIR}/pkg-message
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
