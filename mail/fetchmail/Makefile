# Created by: Ville Eerola <ve@sci.fi>
# $FreeBSD$

PORTNAME?=	fetchmail
DISTVERSION=	6.4.17
CATEGORIES=	mail
# The next line is inherited by the fetchmailconf slave port,
# do NOT replace fetchmail by ${PORTNAME}
MASTER_SITES=	SF/fetchmail/branch_6.4/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT?=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

.if empty(MASTERDIR)
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cpe gmake tar:xz ssl

USERS=		${PORTNAME}
GROUPS=		${USERS}

USE_RC_SUBR=	fetchmail
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes

# the added PYTHON=: suppresses python builds,
# see ../../mail/fetchmailconf/ for the configuration tool
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--without-hesiod --enable-fallback=no \
		--with-ssl=${OPENSSLBASE} PYTHON=:

# -Wl,--as-needed suppresses unneeded library references,
# for instance, libcom_err.so on GSSAPI_NONE builds:
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed

OPTIONS_DEFINE=	CA_BUNDLE NLS DOCS
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	CA_BUNDLE GSSAPI_BASE
OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Install CA bundle for OpenSSL

GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-kerberos5=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

PORTDOCS=	FAQ FEATURES NEWS NOTES OLDNEWS \
		README README.SSL README.SSL-SERVER \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html todo.html

post-patch:
.if !exists(/usr/lib/libcom_err.so)
	@${REINPLACE_CMD} -e "s,-lcom_err,,g" ${WRKSRC}/configure
.endif

.endif

PATCH_STRIP=	-p1

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
