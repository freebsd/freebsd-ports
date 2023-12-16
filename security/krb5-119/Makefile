PORTNAME=		krb5
PORTVERSION=		1.19.4
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=		-119
.endif

DEPRECATED=		Desupported by MIT following 1.21
EXPIRATION_DATE=	2024-06-06

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP=	-p2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		MIT implementation of RFC 4120 network authentication service
WWW=			https://web.mit.edu/kerberos/

LICENSE=		MIT

CONFLICTS=		heimdal krb5 krb5-118 krb5-12*
CONFLICTS_BUILD=	boringssl

KERBEROSV_URL=		http://web.mit.edu/kerberos/
USES=			autoreconf compiler:c++11-lang cpe gmake gettext-runtime \
			gssapi:bootstrap,mit libtool:build localbase \
			perl5 pkgconfig ssl
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated RSA_ routines
BROKEN_FreeBSD_14=	Incompatible with OpenSSL 3.0 in 14-STABLE
BROKEN_FreeBSD_15=	Incompatible with OpenSSL 3.0 in 15-CURRENT
USE_CSTD=		gnu99
USE_LDCONFIG=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS?=	--enable-shared --without-system-verto \
			--disable-rpath
CONFIGURE_ENV=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}" YACC="${YACC}"
MAKE_ARGS=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}"

CPE_VENDOR=		mit
CPE_VERSION=		5-${PORTVERSION}
CPE_PRODUCT=		kerberos

OPTIONS_DEFINE=		EXAMPLES NLS KRB5_PDF KRB5_HTML DNS_FOR_REALM LDAP LMDB
OPTIONS_DEFAULT=	KRB5_PDF KRB5_HTML READLINE
OPTIONS_RADIO=		CMD_LINE_EDITING
OPTIONS_RADIO_CMD_LINE_EDITING=	READLINE LIBEDIT LIBEDIT_BASE
CMD_LINE_EDITING_DESC=	Command line editing for kadmin and ktutil
KRB5_PDF_DESC=		Install krb5 PDF documentation
KRB5_HTML_DESC=		Install krb5 HTML documentation
DNS_FOR_REALM_DESC=	Enable DNS lookups for Kerberos realm names
DNS_FOR_REALM_CONFIGURE_ENABLE=	dns-for-realm
LDAP=			Enable LDAP support
LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap
LMDB_DESC=		OpenLDAP Lightning Memory-Mapped Database support
LMDB_CONFIGURE_WITH=	lmdb
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_IMPLIES=		LDAP
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
READLINE_USES=		readline
READLINE_CONFIGURE_WITH=readline
LIBEDIT_USES=		libedit
LIBEDIT_CONFIGURE_WITH=	libedit
LIBEDIT_BASE_CONFIGURE_WITH=	libedit
LIBEDIT_BASE_DESC=	Use libedit in FreeBSD base

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif
.if !defined(KRB5_LOCALSTATEDIR)
KRB5_LOCALSTATEDIR=	"${PREFIX}/var"
.endif
.if !defined(KRB5_RUNSTATEDIR)
KRB5_RUNSTATEDIR=	"${PREFIX}/var/run"
.endif
CONFIGURE_ARGS+=	--runstatedir="${KRB5_RUNSTATEDIR}"
CONFIGURE_ARGS+=	--localstatedir="${KRB5_LOCALSTATEDIR}"
PLIST_SUB+=		KRB5_LOCALSTATEDIR=${KRB5_LOCALSTATEDIR}
PLIST_SUB+=		KRB5_RUNSTATEDIR=${KRB5_RUNSTATEDIR}
CPPFLAGS+=		-I${OPENSSLINC}
LDFLAGS+=		-L${OPENSSLLIB}

USE_RC_SUBR=		kpropd
OPTIONS_SUB=		yes
WRKSRC_SUBDIR=		src
PORTEXAMPLES=		kdc.conf krb5.conf services.append

.include <bsd.port.options.mk>

# Fix up -Wl,-rpath in LDFLAGS
.if !empty(KRB5_HOME)
_RPATH=	${KRB5_HOME}/lib:
.else
_RPATH=	${LOCALBASE}/lib:
.endif
.if !empty(LDFLAGS:M-Wl,-rpath,*)
.for F in ${LDFLAGS:M-Wl,-rpath,*}
LDFLAGS:=	-Wl,-rpath,${_RPATH}${F:S/-Wl,-rpath,//} \
		${LDFLAGS:N-Wl,-rpath,*}
.endfor
.endif

.if defined(KRB5_HOME) && ${KRB5_HOME} != ${LOCALBASE}
BROKEN=			LIB_DEPENDS when using KRB5_HOME is broken
.endif

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/html
PDF_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/pdf

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5
	@${SED} "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/kdc.in > ${STAGEDIR}${PREFIX}/sbin/kdc; \
	${CHMOD} +x ${STAGEDIR}${PREFIX}/sbin/kdc
# html documentation
.if ${PORT_OPTIONS:MKRB5_PDF}
	pdf_files=`${FIND} ${PDF_DOC_DIR} ! -type d`
	pdf_dirs=`${FIND} ${PDF_DOC_DIR} -type d`
	for i in $${pdf_dirs}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${pdf_files}; do \
		${INSTALL_DATA} $${pdf} ${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
.endif
.if ${PORT_OPTIONS:MKRB5_HTML}
	html_files=`${FIND} ${HTML_DOC_DIR} ! -type d | ${GREP} -v /_sources`
	html_dirs=`${FIND} ${HTML_DOC_DIR} -type d | ${GREP} -v /_sources`
	for i in $${html_dirs}; do \
		${MKDIR} ${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${html_files}; do \
		${INSTALL_DATA} $${i} ${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
.endif
.if ${PORT_OPTIONS:MKRB5_PDF}
	for i in $${pdf_dirs}; do \
		${ECHO_CMD} @dir share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MKRB5_HTML}
	for i in $${html_dirs}; do \
		${ECHO_CMD} @dir share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
.endif
	${ECHO_CMD} @dir share/doc/krb5 >> ${TMPPLIST}

post-install-LDAP-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.schema \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.ldif \
		${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
