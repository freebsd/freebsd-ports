# Created by: Ville Eerola <ve@sci.fi>
# $FreeBSD$

PORTNAME?=	fetchmail
PORTVERSION=	6.3.26
PORTREVISION?=	11
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/${PORTNAME}/branch_6.3/ \
		http://mandree.home.pages.de/${PORTNAME}/

PATCH_SITES=	https://src.fedoraproject.org/rpms/fetchmail/raw/master/f/:fedora
PATCHFILES=	fetchmail-6.3.26-ssl-backport.patch:-p1:fedora

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT?=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

.if empty(MASTERDIR)
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USERS=		${PORTNAME}
GROUPS=		${USERS}

USES=		cpe gmake tar:xz ssl

USE_RC_SUBR=	fetchmail
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes

# the added PYTHON=: suppresses python builds,
# see ../../mail/fetchmailconf/ for the configuration tool
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--without-hesiod --enable-fallback=no \
		--with-ssl=${OPENSSLBASE} PYTHON=:
# In case the user had an SSL-v2-capable SSL build, disable it:
CONFIGURE_ENV=	ac_cv_have_decl_SSLv2_client_method=no

# -Wl,--as-needed suppresses unneeded library references,
# for instance, libcom_err.so on GSSAPI_NONE builds:
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed

OPTIONS_DEFINE=	NLS NTLM POP2 DOCS
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SUB=	yes

GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-kerberos5=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

POP2_DESC=	POP2 Protocol support [obsolete]

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

NTLM_CONFIGURE_ENABLE=	NTLM
NTLM_PORTDOCS=		README.NTLM

# POP2 is obsolete
POP2_CONFIGURE_ENABLE=	POP2

PORTDOCS=	FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

post-patch:
.if !exists(/usr/lib/libcom_err.so)
	@${REINPLACE_CMD} -e "s,-lcom_err,,g" ${WRKSRC}/configure
.endif

.endif

# this avoids rebuilding the autotools rigs, i. e. USES+=autoreconf.
# It will clobber the AC_CHECK_DECLS([SSLv3_client_method],,,[#include <openssl/ssl.h>])
# so we've put that into files/patch-configure as well:
pre-configure:
	@${TOUCH} -d 2010-01-01T00:00:00 ${WRKSRC}/configure.ac

.if empty(MASTERDIR)
post-build:
	${MAKE_CMD} -C ${WRKSRC} check

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
.include <bsd.port.mk>
