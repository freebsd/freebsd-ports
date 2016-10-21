# $FreeBSD$

PORTNAME=	cyrus-imapd
PORTVERSION=	2.3.19
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-imapd/
PKGNAMESUFFIX=	23

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libpcre.so:devel/pcre

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^3].* cyrus-imapd2[^3]-2.[^3].*

USE_RC_SUBR=	imapd

USES=		cpe perl5
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CYRUS_PREFIX=	${PREFIX}/cyrus
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${CYRUS_PREFIX} \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb=${BDB_LIB_NAME} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

CPE_VENDOR=	cmu
CPE_PRODUCT=	cyrus_imap_server

OPTIONS_DEFINE=		AUTOCREATE AUTOSIEVE BDB DRAC IDLED \
			LDAP_PTLOADER LISTEXT MURDER MYSQL \
			NETSCAPEHACK NNTP PGSQL REPLICATION SNMP_5 \
			SQLITE DOCS EXAMPLES
OPTIONS_DEFAULT=	BDB
OPTIONS_SUB=		yes
AUTOCREATE_DESC=	Use autocreate INBOX patch (UoA)
AUTOSIEVE_DESC=		Use autosievefolder patch (UoA)
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb-libdir=${LOCALBASE}/lib
DRAC_DESC=		Enable DRAC support
DRAC_CONFIGURE_ON=	--with-drac=${LOCALBASE}
DRAC_BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:mail/drac
IDLED_DESC=		Enable IMAP idled support
IDLED_CONFIGURE_ENABLE=	idled
LDAP_PTLOADER_DESC=	Enable LDAP ptloader
LDAP_PTLOADER_USE=	OPENLDAP=yes
LDAP_PTLOADER_CONFIGURE_ON=--with-ldap=${LOCALBASE}
LISTEXT_DESC=		Enable IMAP List extensions
LISTEXT_CONFIGURE_ENABLE=listext
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_MAKE_ENV=	PTHREAD_LIBS="-lpthread"
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=yes \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include/mysql
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NETSCAPEHACK_CONFIGURE_ENABLE=netscapehack
NNTP_DESC=		Enable NNTP support
NNTP_CONFIGURE_ENABLE=	nntp
PGSQL_DESC=		Enable PostgreSQL backend (experimental)
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
REPLICATION_DESC=	Enable replication
REPLICATION_CONFIGURE_ENABLE=replication
SNMP_5_DESC=		Enable SNMP support
SNMP_5_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_5_CONFIGURE_ON=	--with-snmp=${LOCALBASE}
SNMP_5_CONFIGURE_OFF=	--with-snmp=no
SQLITE_DESC=		Enable SQLite backend (experimental)
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}

# Autocreate Inbox and Autosieve patches from UoA
# WWW: http://email.uoa.gr/projects/cyrus/

AUTOCREATE_VERSION=	0.10-0
AUTOCREATE_PATCH_SITES=	http://email.uoa.gr/download/cyrus/${PORTNAME}-2.3.16/:autocreate
AUTOCREATE_PATCHFILES=	${PORTNAME}-2.3.16-autocreate-${AUTOCREATE_VERSION}.diff:autocreate

AUTOSIEVE_VERSION=	0.6.0
AUTOSIETE_PATCH_SITES=	http://email.uoa.gr/download/cyrus/${PORTNAME}-2.3.16/:autosieve
AUTOSIEVE_PATCHFILES=	${PORTNAME}-2.3.16-autosieve-${AUTOSIEVE_VERSION}.diff
AUTOSIEVE_BROKEN=	Not buildable with autosieve patch

DRAC_EXTRA_PATCHES=	${WRKSRC}/contrib/drac_auth.patch \
			${FILESDIR}/extra-patch-configure.in \
			${FILESDIR}/extra-patch-cmulocal_ucdsnmp.m4 \
			${FILESDIR}/extra-patch-cmulocal_sasl2.m4
DRAC_USE=	AUTOTOOLS=autoconf,autoheader

MANDIRS=	${CYRUS_PREFIX}/man

PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall cyrus-imapd-man.conf

SUB_LIST=	CYRUS_USER=${CYRUS_USER} CYRUS_GROUP=${CYRUS_GROUP}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN_MAN1=	imtest installsieve lmtptest mupdatetest nntptest pop3test \
		sieveshell sivtest smtptest
MAN_MAN3=	imclient
MAN_MAN5=	cyrus.conf imapd.conf krb.equiv

CYRUS_MAN8=	arbitron chk_cyrus ctl_cyrusdb ctl_deliver ctl_mboxlist \
		cvt_cyrusdb cyr_dbtool cyr_df cyr_expire cyr_synclog deliver \
		fetchnews fud idled imapd ipurge lmtpd make_md5 make_sha1 \
		master mbexamine mbpath nntpd notifyd pop3d quota reconstruct \
		rmnews smmapd squatter sync_client sync_reset sync_server \
		syncnews timsieved tls_prune unexpunge

CYRUS_PERL_MAN1=cyradm
CYRUS_PERL_MAN3=Cyrus::IMAP Cyrus::IMAP::Admin Cyrus::IMAP::IMSP \
		Cyrus::IMAP::Shell Cyrus::SIEVE::managesieve

CONFS=		cmu-backend.conf cmu-frontend.conf normal.conf prefork.conf \
		small.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
INVALID_BDB_VER=2
.else
BDB_LIB_NAME=	no
.endif

.if !exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--disable-gssapi
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
			  -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			  -e "s|%%CYRUS_GROUP%%|${CYRUS_GROUP}|g" \
		${WRKSRC}/tools/mkimap
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|g" \
			  -e "s|/usr/sieve|/var/imap/sieve|g" \
		${WRKSRC}/tools/masssievec

post-patch-DRAC-on:
	@${RM} -r ${WRKSRC}/autom4te.cache

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${CYRUS_PREFIX}/bin/mkimap
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${CYRUS_PREFIX}/bin/masssievec
	${INSTALL_DATA} ${WRKDIR}/cyrus-imapd-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/cyrus-imapd.conf
.for s in 1 3 5
.  for m in ${MAN_MAN${s}}
	@${ECHO_CMD} man/man${s}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for s in 1 3
.  for m in ${CYRUS_PERL_MAN${s}}
	@${ECHO_CMD} ${SITE_MAN${s}}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for m in ${CYRUS_MAN8}
	@${ECHO_CMD} ${CYRUS_PREFIX}/man/man8/${m}.8.gz >> ${TMPPLIST}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! ( -name Makefile.dist -o -name Makefile \
		-o -name .cvsignore -o -name htmlstrip.c )"

# There are already files in EXAMPLESDIR at that point, so no
# need to create it.
post-install-EXAMPLES-on:
.for f in ${CONFS:Nnormal.conf}
	@${INSTALL_DATA} ${WRKSRC}/master/conf/${f} \
		${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor

.include <bsd.port.mk>
