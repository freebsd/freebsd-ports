# New ports collection makefile for:	cyrus-sasl2-saslauthd
# Date created:				May 27 2003
# Whom:					ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	saslauthd
PORTVERSION=	2.1.15
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl
PKGNAMEPREFIX=	cyrus-sasl-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SASL authentication server for cyrus-sasl2

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

CYRUS_SASL2_DIR=${MASTERDIR}/../cyrus-sasl2
MD5_FILE=	${CYRUS_SASL2_DIR}/distinfo
PATCHDIR=	${CYRUS_SASL2_DIR}/files
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/saslauthd
DOCSDIR=	${PREFIX}/share/doc/cyrus-sasl2

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
		--includedir=${PREFIX}/include \
		--mandir=${MANPREFIX}/man \
		--enable-static \
		--enable-login \
		--enable-auth-sasldb \
		--with-rc4=openssl \
		--with-saslauthd

.if defined(WITH_BDB_VER)
.if ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-bdb=db41 --with-bdb-incdir=${PREFIX}/include/db41
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=--with-bdb=db4 --with-bdb-incdir=${PREFIX}/include/db4
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=--with-bdb=db3 --with-bdb-incdir=${PREFIX}/include/db3
.else
BROKEN=		"WITH_BDB_VER must be 3, 4 or 41"
.endif
CONFIGURE_ARGS+=--with-dblib=berkeley --with-bdb-libdir=${PREFIX}/lib
.else
CONFIGURE_ARGS+=--with-dblib=ndbm
.endif

.if defined(WITH_OPENLDAP_VER)
.if ${WITH_OPENLDAP_VER} == 20 || ${WITH_OPENLDAP_VER} == 21 || \
    ${WITH_OPENLDAP_VER} == 22
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap${WITH_OPENLDAP_VER}-client
LIB_DEPENDS+=	lber.2:${PORTSDIR}/net/openldap${WITH_OPENLDAP_VER}-client
CONFIGURE_ARGS+=--with-ldap=${PREFIX}
.else
BROKEN=		"WITH_OPENLDAP_VER must be 20, 21 or 22"
.endif
.endif

.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=--enable-gssapi=${KRB5_HOME}
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=--enable-gssapi=${HEIMDAL_HOME}
.elif !defined(WITHOUT_GSSAPI) && defined(MAKE_KERBEROS5) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--enable-gssapi
.else
CONFIGURE_ARGS+=--disable-gssapi
.endif

.include <bsd.port.pre.mk>

# KERBEROS 4 was removed in FreeBSD 5.0-CURRENT
.if ${OSVERSION} > 500105
.if defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=--disable-krb4
.endif
.elif exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4) && !defined(WITHOUT_KERBEROS4)
CONFIGURE_ARGS+=--enable-krb4
.elif !exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=--disable-krb4
.endif

.include "${PORTSDIR}/security/openssl/bsd.openssl.mk"
.if !defined(WITH_OPENSSL_BASE)
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB} \
		LDFLAGS=${LDFLAGS}

CYRUS_USER?=	cyrus

DOCS=		AUTHORS COPYING ChangeLog INSTALL LDAP_SASLAUTHD NEWS README

PLIST_SUB=	PREFIX=${PREFIX} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///}

do-build:
	@${RM} -f ${WRKSRC}/saslauthd/saslauthd.8
	cd ${WRKSRC}/sasldb && ${MAKE}
	cd ${WRKSRC}/saslauthd && ${MAKE}

post-install:
	${GZIP_CMD} ${MAN8PREFIX}/man/cat8/saslauthd.8
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" \
		${FILESDIR}/saslauthd.sh > ${PREFIX}/etc/rc.d/saslauthd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/saslauthd.sh
	${MKDIR} -m 770 /var/state/saslauthd
	${CHOWN} ${CYRUS_USER}:mail /var/state/saslauthd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/saslauthd
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/saslauthd/${file} ${DOCSDIR}/saslauthd
.endfor
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} \
		POST-INSTALL

.include <bsd.port.post.mk>
