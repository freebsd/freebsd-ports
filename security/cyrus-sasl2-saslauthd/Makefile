# New ports collection makefile for:	cyrus-sasl2-saslauthd
# Date created:				May 27 2003
# Whom:					ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	saslauthd
PORTVERSION=	2.1.20
#PORTREVISION=	0
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

USE_RC_SUBR=	YES

USE_OPENSSL=	yes
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
		--with-saslauthd=${SASLAUTHD_RUNPATH}

.if defined(WITH_BDB_VER)
.if ${WITH_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db3 --with-bdb=db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db4 --with-bdb=db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db41 --with-bdb=db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db42 --with-bdb=db-4.2
.else
BROKEN=		"WITH_BDB_VER must be 3, 4, 41 or 42"
.endif
CONFIGURE_ARGS+=--with-dblib=berkeley --with-bdb-libdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--with-dblib=ndbm
.endif

.if defined(WITH_OPENLDAP_VER)
WITH_OPENLDAP=		yes
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
.if defined(WITH_OPENLDAP)
.if defined(WANT_OPENLDAP_VER) && ${WANT_OPENLDAP_VER} == 12
BROKEN=		"this port requires OpenLDAP >= 2.0"
.endif
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=--enable-gssapi=${KRB5_HOME} --with-gss_impl=mit
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=--enable-gssapi=${HEIMDAL_HOME} --with-gss_impl=heimdal
.elif !defined(WITHOUT_GSSAPI) && ( defined(MAKE_KERBEROS5) || ${OSVERSION} > 500105 ) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--enable-gssapi
.else
CONFIGURE_ARGS+=--disable-gssapi
.endif

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

.if ${OPENSSLBASE} == /usr
CONFIGURE_ARGS+=--with-openssl=yes
.else
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

SASLAUTHD_RUNPATH?=	/var/state/saslauthd
.if ${SASLAUTHD_RUNPATH} != /var/state/saslauthd
RUNPATH=	"@comment "
.endif

CYRUS_USER?=	cyrus

DOCS=		AUTHORS COPYING ChangeLog INSTALL LDAP_SASLAUTHD NEWS README

PLIST_SUB=	PREFIX=${PREFIX} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \
		RUNPATH=${RUNPATH}

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR} \
		SASLAUTHD_RUNPATH=${SASLAUTHD_RUNPATH}

do-build:
	@${RM} -f ${WRKSRC}/saslauthd/saslauthd.8
	cd ${WRKSRC}/include && ${MAKE}
	cd ${WRKSRC}/sasldb && ${MAKE}
	cd ${WRKSRC}/saslauthd && ${MAKE}

post-install:
	${GZIP_CMD} ${MAN8PREFIX}/man/cat8/saslauthd.8
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/saslauthd.sh > ${PREFIX}/etc/rc.d/saslauthd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/saslauthd.sh
.if ${SASLAUTHD_RUNPATH} != /var/state/saslauthd
	@${ECHO_MSG} ""
	@${ECHO_MSG} "SASLAUTHD_RUNPATH was specified."
	@${ECHO_MSG} "Make sure to have ${SASLAUTHD_RUNPATH} by yourself."
	@${ECHO_MSG} ""
.else
	${MKDIR} -m 770 ${SASLAUTHD_RUNPATH}
	${CHOWN} ${CYRUS_USER}:mail ${SASLAUTHD_RUNPATH}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/saslauthd
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/saslauthd/${file} ${DOCSDIR}/saslauthd
.endfor
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} \
		POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
