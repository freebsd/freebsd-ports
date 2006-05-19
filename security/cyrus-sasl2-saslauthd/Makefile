# New ports collection makefile for:	cyrus-sasl2-saslauthd
# Date created:				May 27 2003
# Whom:					ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	saslauthd
PORTVERSION=	2.1.22
PORTREVISION=	0
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

USE_RC_SUBR=	saslauthd.sh

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

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
.if ${WITH_BDB_VER} == 4
USE_BDB=	40
.elif ${WITH_BDB_VER} != 3 && ${WITH_BDB_VER} != 41 && \
      ${WITH_BDB_VER} != 42 && ${WITH_BDB_VER} != 43 && ${WITH_BDB_VER} != 44
IGNORE=		"cannot install: WITH_BDB_VER must be 3, 4, 41, 42, 43 or 44"
.endif
USE_BDB?=	${WITH_BDB_VER}
BDB_SUFFIX?=	${WITH_BDB_VER}
CONFIGURE_ARGS+=--with-dblib=berkeley --with-bdb-libdir=${LOCALBASE}/lib \
		--with-bdb-incdir=${BDB_INCLUDE_DIR} \
		--with-bdb=${BDB_LIB_NAME}
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

.if defined(WITH_HTTPFORM)
CONFIGURE_ARGS+=--enable-httpform
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

SASLAUTHD_RUNPATH?=	/var/run/saslauthd
.if ${SASLAUTHD_RUNPATH} != /var/run/saslauthd
RUNPATH=	"@comment "
.endif

CYRUS_USER?=	cyrus

DOCS=		AUTHORS COPYING ChangeLog INSTALL LDAP_SASLAUTHD NEWS README

PLIST_SUB=	PREFIX=${PREFIX} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \
		RUNPATH=${RUNPATH}

SUB_LIST+=	SASLAUTHD_RUNPATH=${SASLAUTHD_RUNPATH}

do-build:
	@${RM} -f ${WRKSRC}/saslauthd/saslauthd.8
	cd ${WRKSRC}/include && ${MAKE}
	cd ${WRKSRC}/sasldb && ${MAKE}
	cd ${WRKSRC}/saslauthd && ${MAKE}
	cd ${WRKSRC}/saslauthd && ${MAKE} saslcache
	cd ${WRKSRC}/saslauthd && ${MAKE} testsaslauthd

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/saslauthd/saslcache \
		${PREFIX}/sbin/saslcache
	@${INSTALL_PROGRAM} ${WRKSRC}/saslauthd/testsaslauthd \
		${PREFIX}/sbin/testsaslauthd
	${GZIP_CMD} ${MAN8PREFIX}/man/cat8/saslauthd.8
.if ${SASLAUTHD_RUNPATH} != /var/run/saslauthd
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
