PORTNAME=	pam_pkcs11
PORTVERSION=	0.6.12
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security

MAINTAINER=	khng@FreeBSD.org
COMMENT=	PAM module using crypto tokens for auth
WWW=		https://github.com/OpenSC/pam_pkcs11

LICENSE=	LGPL21

RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gettext-tools gmake libtool pkgconfig shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSC

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-confdir=${ETCDIR}
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

SHEBANG_FILES=	tools/pkcs11_make_hash_link

OPTIONS_DEFINE=		CURL DEBUG DOCS LDAP NLS NSS PCSC SSL
OPTIONS_DEFAULT=	PCSC SSL
OPTIONS_SUB=		yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap

# Users can only choose either NSS or SSL
NSS_DESC=		Enable Mozilla's NSS support
NSS_CONFIGURE_WITH=	nss
NSS_LIB_DEPENDS=	libnss3.so:security/nss \
			libnspr4.so:devel/nspr
NSS_PREVENTS=		SSL

PCSC_DESC=		Enable PC/SC support
PCSC_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
PCSC_CONFIGURE_WITH=	pcsclite

SSL_USES=		ssl

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

DOCS_CONFIGURE_ENABLE=	doc

PORTDOCS=	*

PAM_PKCS11_EXAMPLEDOCS=	\
	etc/card_eventmgr.conf.example		\
	etc/digest_mapping.example		\
	etc/mail_mapping.example		\
	etc/pam.d_login.example.in		\
	etc/pam_pkcs11.conf.example.in		\
	etc/pkcs11_eventmgr.conf.example	\
	etc/subject_mapping.example

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
INSTALL_TARGET=		install-strip
.else
CONFIGURE_ARGS+=	--with-debug=yes
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
CONFIGURE_ENV+=	XSLTPROC="${LOCALBASE}/bin/xsltproc"
CONFIGURE_ARGS+=--with-xsl-stylesheetsdir=${LOCALBASE}/share/xsl/docbook
.else
CONFIGURE_ENV+=	XSLTPROC="${FALSE}"
CONFIGURE_ARGS+=--without-xsl-stylesheetsdir
.endif

post-patch:
.for f in ${PAM_PKCS11_EXAMPLEDOCS}
	@${REINPLACE_CMD} -e 's|/etc/${PORTNAME}|${ETCDIR}|g'		\
		-e 's|file:///etc/${PORTNAME}/|file://${ETCDIR}/|g'	\
		-e 's|/usr/lib|${PREFIX}/lib|g'				\
		-e 's|/usr/share|${PREFIX}/share|g'			\
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g'	\
		${WRKSRC}/doc/pam_pkcs11.8.in

.include <bsd.port.mk>
