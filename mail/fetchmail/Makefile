# Created by: Ville Eerola <ve@sci.fi>

PORTNAME?=	fetchmail
DISTVERSION=	6.4.31
PORTREVISION?=	0
CATEGORIES=	mail
# The next line is inherited by the fetchmailconf dependent port,
# do NOT replace fetchmail by ${PORTNAME}
MASTER_SITES=	SF/fetchmail/branch_6.4/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT?=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

LICENSE=	GPLv2+

.if empty(MASTERDIR)
USES=		cpe gmake tar:xz
IGNORE_SSL=	libressl libressl-devel
IGNORE_SSL_REASON=	incompatible license/no GPLv2 clause 2b exception for LibreSSL
# The Free Software Foundation asserts that a GPL v2 clause 2b exception is
# required even for dynamically linked binaries. See
# https://www.gnu.org/licenses/gpl-faq.en.html#GPLStaticVsDynamic

USE_RC_SUBR=	fetchmail

GNU_CONFIGURE=	yes

# the added PYTHON=: suppresses python builds,
# see ../../mail/fetchmailconf/ for the configuration tool
CONFIGURE_ARGS=	--enable-fallback=no \
		--enable-opie \
		--enable-RPA \
		--enable-SDPS \
		--without-hesiod \
		PYTHON=:

# -Wl,--as-needed suppresses unneeded library references,
# for instance, libcom_err.so on GSSAPI_NONE builds:
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed

PATCH_STRIP=	-p1
SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	FAQ FEATURES NEWS NOTES OLDNEWS README README.SSL \
		README.SSL-SERVER design-notes.html esrs-design-notes.html \
		fetchmail-FAQ.html fetchmail-features.html todo.html

OPTIONS_DEFINE=		CA_BUNDLE DOCS NLS
OPTIONS_DEFAULT=	CA_BUNDLE GSSAPI_BASE OPENSSL
OPTIONS_SINGLE=		GSSAPI TLS
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_TLS=	OPENSSL WOLFSSL

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-kerberos5=${GSSAPIBASEDIR}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

OPENSSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE}

WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
WOLFSSL_USES_OFF=	ssl
WOLFSSL_CONFIGURE_ON=	WOLFSSL_TRUST_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
WOLFSSL_CONFIGURE_WITH=	wolfssl=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's,krb5_des_string_to_key,krb5int_des_init_state,g' ${WRKSRC}/configure
.if !exists(/usr/lib/libcom_err.so)
	@${REINPLACE_CMD} -e "s,-lcom_err,,g" ${WRKSRC}/configure
.endif

.endif

.if empty(MASTERDIR)
post-build:
	${MAKE_CMD} -C ${WRKSRC} check ; { r=$$? ; ( set -x ; ${CAT} "${WRKSRC}/test-suite.log" ) ; exit $$r ; }

post-install:
	${INSTALL} -d ${STAGEDIR}/var/run/fetchmail
	${INSTALL_DATA} ${FILESDIR}/fetchmailrc.sample \
		${STAGEDIR}${PREFIX}/etc/fetchmailrc.sample
	${RM} ${STAGEDIR}${PREFIX}/bin/fetchmailconf
	${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmailconf.1*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.endif

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*} && ${OSREL:R} < 13
# as of 2019-10-02, powerpc's base compiler does not yield a working fetchmail.
# https://svnweb.freebsd.org/ports?view=revision&revision=513614 -- pkubaj@
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
