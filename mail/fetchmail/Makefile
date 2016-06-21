# Created by: Ville Eerola <ve@sci.fi>
# $FreeBSD$

PORTNAME=	fetchmail
PORTVERSION=	6.3.26
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/${PORTNAME}/branch_6.3/ \
		http://mandree.home.pages.de/${PORTNAME}/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USERS=		${PORTNAME}
GROUPS=		${USERS}

USES=		cpe gmake shebangfix tar:xz
SHEBANG_FILES=	fetchmailconf.py

USE_RC_SUBR=	fetchmail
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--without-hesiod --enable-fallback=no \
		--with-ssl=${OPENSSLBASE}
CONFIGURE_ENV=	ac_cv_have_decl_SSLv2_client_method=no

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	X11 NLS NTLM POP2 DOCS
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SUB=	yes

GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

X11_DESC=	Python/Tkinter dependencies for ``fetchmailconf''
POP2_DESC=	POP2 Protocol support[obsolete]

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

NTLM_CONFIGURE_ENABLE=	NTLM
NTLM_PORTDOCS=		README.NTLM

# POP2 is obsolete
POP2_CONFIGURE_ENABLE=	POP2

X11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter
X11_USES=	python
X11_CONFIGURE_OFF=	PYTHON=:
X11_SUB_FILES_OFF=	fetchmailconf

PORTDOCS=	FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

#.include <bsd.port.options.mk>

post-patch:
.if !exists(/usr/lib/libcom_err.so)
	@${REINPLACE_CMD} -e "s,-lcom_err,,g" ${WRKSRC}/configure
.endif

post-build:
	@${MAKE_CMD} -C ${WRKSRC} check

post-stage:
	${INSTALL} -d ${STAGEDIR}/var/run/fetchmail
	${INSTALL_DATA} ${FILESDIR}/fetchmailrc.sample \
		${STAGEDIR}${PREFIX}/etc/fetchmailrc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-X11-off:
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
