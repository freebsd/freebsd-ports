# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		krb5
PORTVERSION=		1.14.6
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=		-114
.endif

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP=	-p2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		MIT implementation of RFC 4120 network authentication service

LICENSE=		MIT

DEPRECATED=		EOL twelve months after release of krb5-1.16
EXPIRATION_DATE=	2018-12-31

CONFLICTS=		heimdal-[0-9]* srp-[0-9]* krb5-11[35]-[0-9]* \
			krb5-1.[0-9]* krb5-devel-*

KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_CSTD=		gnu99
GNU_CONFIGURE=		yes
USES=			cpe gmake localbase perl5 libtool:build \
			gssapi:bootstrap,mit pkgconfig:run ssl
CONFIGURE_ARGS?=	--enable-shared --without-system-verto \
			--disable-rpath --localstatedir="${PREFIX}/var"
CONFIGURE_ENV=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}" YACC="${YACC}"
MAKE_ARGS=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}"

CPE_VENDOR=		mit
CPE_VERSION=		5-${PORTVERSION}
CPE_PRODUCT=		kerberos

OPTIONS_DEFINE=		EXAMPLES NLS KRB5_PDF KRB5_HTML DNS_FOR_REALM LDAP
OPTIONS_DEFAULT=	KRB5_PDF KRB5_HTML READLINE
OPTIONS_RADIO=		CMD_LINE_EDITING
OPTIONS_RADIO_CMD_LINE_EDITING=	READLINE READLINE_PORT LIBEDIT
CMD_LINE_EDITING_DESC=	Command line editing for kadmin and ktutil
KRB5_PDF_DESC=		Install krb5 PDF documentation
KRB5_HTML_DESC=		Install krb5 HTML documentation
DNS_FOR_REALM_DESC=	Enable DNS lookups for Kerberos realm names
DNS_FOR_REALM_CONFIGURE_ENABLE=	dns-for-realm
LDAP=			Enable LDAP support
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
NLS_USES=		gettext
READLINE_USES=		readline
READLINE_PORT_DESC=	Command line editing via devel/readline
READLINE_PORT_USES=	readline:port
LIBEDIT_USES=		libedit
LIBEDIT_CONFIGURE_WITH=	libedit

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif
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

# OPTIONS helper causes conflicting with/without
.if ${PORT_OPTIONS:MREADLINE} || ${PORT_OPTIONS:MREADLINE_PORT}
CONFIGURE_ARGS+=	--with-readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/html
PDF_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/pdf

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5
# html documentation
.if ${PORT_OPTIONS:MKRB5_PDF}
	pdf_files=`${FIND} ${PDF_DOC_DIR} ! -type d`
	pdf_dirs=`${FIND} ${PDF_DOC_DIR} -type d`
	for i in $${pdf_dirs}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${pdf_files}; do \
		${INSTALL_MAN} $${pdf} ${PREFIX}/share/doc/krb5/$${i}; \
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
		${INSTALL_MAN} $${i} ${PREFIX}/share/doc/krb5/$${i}; \
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

.include <bsd.port.mk>
