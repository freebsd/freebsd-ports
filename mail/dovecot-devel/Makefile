# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	0.99.8
CATEGORIES=	mail ipv6
MASTER_SITES=	http://dovecot.procontrol.fi/test/
DISTNAME=	${PORTNAME}-${PORTVERSION}-test5

MAINTAINER=	d.marks@student.umist.ac.uk

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-shadow --enable-ipv6 \
		--localstatedir=/var/dovecot --with-ssl=openssl \
		--with-ssldir=/var/dovecot/ssl --with-pop3d \
		--with-ldap --with-pam

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

pre-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/dovecot
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/imap/imap \
		${WRKSRC}/src/pop3/pop3 \
		${WRKSRC}/src/auth/dovecot-auth \
		${WRKSRC}/src/imap-login/imap-login \
		${WRKSRC}/src/pop3-login/pop3-login \
			${PREFIX}/lib/dovecot/
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf ${PREFIX}/etc/
	${INSTALL_PROGRAM} ${WRKSRC}/src/master/dovecot ${PREFIX}/sbin/

post-install:
	@${MKDIR} /var/dovecot
	@${MKDIR} /var/dovecot/ssl
	@${MKDIR} /var/dovecot/auth
	@${MKDIR} /var/dovecot/login
	@${CHOWN} -R imapd:imapd /var/dovecot
	@if [ ! -f ${PREFIX}/etc/rc.d/dovecot-imapd.sh ]; then \
		${ECHO} "Installing dovecot-imapd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dovecot-imapd.sh \
			${PREFIX}/etc/rc.d/dovecot-imapd.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dovecot
	@${INSTALL_DATA} \
		${WRKSRC}/doc/auth.txt \
		${WRKSRC}/doc/design.txt \
		${WRKSRC}/doc/index.txt \
		${WRKSRC}/doc/multiaccess.txt \
		${WRKSRC}/doc/nfs.txt \
		${WRKSRC}/doc/configuration.txt \
		${WRKSRC}/doc/mail-storages.txt \
			${PREFIX}/share/doc/dovecot
.endif

.include <bsd.port.mk>
