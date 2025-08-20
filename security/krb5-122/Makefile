PORTNAME=		krb5
PORTVERSION=		1.22
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
.if !defined(MASTERDIR)
PKGNAME_X=		-${FLAVOR:S/default//}-122
.else
PKGNAME_X=		-${FLAVOR:S/default//}
.endif
PKGNAMESUFFIX=		${PKGNAME_X:S/--/-/:C/-$//}

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP=	-p2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		MIT implementation of RFC 4120 network authentication service
WWW=			https://web.mit.edu/kerberos/

LICENSE=		MIT

CONFLICTS=		heimdal krb5 krb5-11* krb5-120
CONFLICTS_BUILD=	boringssl

KERBEROSV_URL=		http://web.mit.edu/kerberos/
USES=			autoreconf compiler:c++11-lang cpe gmake gettext-runtime \
			gssapi:bootstrap,mit libtool:build localbase \
			perl5 pkgconfig ssl
USE_CSTD=		gnu99
USE_LDCONFIG=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS?=	--enable-shared --without-system-verto \
			--disable-rpath
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}" YACC="${YACC}"
MAKE_ARGS=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}"

CPE_VENDOR=		mit
CPE_VERSION=		5-${PORTVERSION}
CPE_PRODUCT=		kerberos

FLAVORS=		default ldap

OPTIONS_DEFINE=		EXAMPLES NLS DOCS DNS_FOR_REALM LDAP LMDB
OPTIONS_DEFAULT=	DOCS READLINE
OPTIONS_RADIO=		CMD_LINE_EDITING
OPTIONS_RADIO_CMD_LINE_EDITING=	READLINE LIBEDIT LIBEDIT_BASE
CMD_LINE_EDITING_DESC=	Command line editing for kadmin and ktutil
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

.if ${FLAVOR:U} == ldap
OPTIONS_DEFAULT+=	LDAP LMDB
.endif

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

.include <bsd.port.pre.mk>

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
	pdf_files=`${FIND} doc/pdf ! -type d`; \
	pdf_dirs=`${FIND} doc/pdf -type d`; \
	for i in $${pdf_dirs}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${pdf_files}; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
	for i in $${pdf_dirs}; do \
		${ECHO_CMD} @dir share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
	html_files=`${FIND} doc/html ! -type d | ${GREP} -v /_sources`; \
	html_dirs=`${FIND} doc/html -type d | ${GREP} -v /_sources`; \
	for i in $${html_dirs}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${html_files}; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
	for i in $${html_dirs}; do \
		${ECHO_CMD} @dir share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
	${ECHO_CMD} @dir share/doc/krb5 >> ${TMPPLIST}

post-install-LDAP-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.schema \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.ldif \
		${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
