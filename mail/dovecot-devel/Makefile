# ex:ts=8
# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot
DISTVERSION=	1.0.alpha5
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/

MAINTAINER=	robin@isometry.net
COMMENT=	Secure and compact IMAP and POP3 servers

USE_ICONV=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-shadow --with-pam \
		--localstatedir=/var --with-ssl=openssl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	USE-WIKI-INSTEAD \
		auth-protocol.txt auth.txt configuration.txt design.txt \
		index.txt mail-storages.txt multiaccess.txt nfs.txt \
		securecoding.txt variables.txt

OPTIONS=	SASL2		"SASL2 support"		off \
		GSSAPI		"GSSAPI support"	off \
		VPOPMAIL	"VPopMail support"	off \
		LDAP		"OpenLDAP support"	off \
		PGSQL		"PostgreSQL support"	off \
		MYSQL		"MySQL support"		off \
		RCORDER		"RC Order support"	off

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500038 ) || !defined(WITH_RCORDER)
USE_RC_SUBR=	dovecot.sh
.else
USE_RCORDER=	dovecot.sh
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

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/^\(SUBDIRS = src\) doc/\1/' \
		${WRKSRC}/Makefile.in
.endif

post-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
