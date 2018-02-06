# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		krb5
PORTVERSION=		1.17.${MIT_COMMIT_DATE}
CATEGORIES=		security
.if !defined(MASTERDIR)
PKGNAMESUFFIX=		-devel
.endif
HASH=			364c608 
MIT_COMMIT_DATE=	2018.02.06

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP=	-p2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		MIT implementation of RFC 4120 network authentication service

LICENSE=		MIT

USE_GITHUB=		yes
GH_TAGNAME=		${HASH}

CONFLICTS=		heimdal-[0-9]* srp-[0-9]* krb5-11[345]-[0-9]* \
			krb5-1.[0-9]*

KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_CSTD=		gnu99
GNU_CONFIGURE=		yes
USES=			autoreconf cpe gmake localbase perl5 libtool:build \
			gssapi:bootstrap,mit pkgconfig:run ssl
CONFIGURE_ARGS?=	--enable-shared --without-system-verto \
			--disable-rpath --localstatedir="${PREFIX}/var"
CONFIGURE_ENV=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}" YACC="${YACC}"
MAKE_ARGS=		INSTALL="${INSTALL}" INSTALL_LIB="${INSTALL_LIB}"

CPE_VENDOR=		mit
CPE_VERSION=		5-${PORTVERSION}
CPE_PRODUCT=		kerberos

OPTIONS_DEFINE=		EXAMPLES NLS DNS_FOR_REALM LDAP
OPTIONS_DEFAULT=	KRB5_PDF KRB5_HTML READLINE
OPTIONS_RADIO=		CMD_LINE_EDITING
OPTIONS_RADIO_CMD_LINE_EDITING=	READLINE READLINE_PORT LIBEDIT
CMD_LINE_EDITING_DESC=	Command line editing for kadmin and ktutil
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

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/krb5
	${ECHO_CMD} @dir share/doc/krb5 >> ${TMPPLIST}

post-install-LDAP-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.schema \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/kdb/ldap/libkdb_ldap/kerberos.ldif \
		${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
