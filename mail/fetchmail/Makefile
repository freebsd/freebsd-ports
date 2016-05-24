# Created by: Ville Eerola <ve@sci.fi>
# $FreeBSD$

PORTNAME=	fetchmail
PORTVERSION=	6.3.26
PORTREVISION=	3
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/${PORTNAME}/branch_6.3/ \
		http://mandree.home.pages.de/${PORTNAME}/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

# Note USERS can only contain a single word as parts below rely on that.
USERS=		${PORTNAME}
GROUPS=		${USERS}

USES=		cpe gmake shebangfix tar:xz
SHEBANG_FILES=	fetchmailconf.py

USE_RC_SUBR=	fetchmail
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} PORTNAME=${PORTNAME}

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--without-hesiod --enable-fallback=no \
		--with-ssl=${OPENSSLBASE}
CONFIGURE_ENV=	ac_cv_have_decl_SSLv2_client_method=no

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	X11 NLS NTLM GSSAPI POP2 DOCS
OPTIONS_DEFAULT=	GSSAPI
OPTIONS_SUB=	yes
X11_DESC=	Python/Tkinter dependencies for ``fetchmailconf''
POP2_DESC=	POP2 Protocol support[obsolete]

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--enable-nls
NLS_CONFIGURE_OFF=	--disable-nls

PORTDOCS=	FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

.include <bsd.port.options.mk>

# Pop2 is obsolete
.if ${PORT_OPTIONS:MPOP2}
CONFIGURE_ARGS+=	--enable-POP2
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		python
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter
PLIST_SUB+=	NOX11="@comment "
.else
CONFIGURE_ARGS+=	PYTHON=:
SUB_FILES+=	fetchmailconf
PLIST_SUB+=	NOX11=""
.endif

.if ${PORT_OPTIONS:MGSSAPI}
.if !defined(KRB5_HOME)
.if exists(${LOCALBASE}/lib/libkrb5.a)
KRB5_HOME=	${LOCALBASE}
.elif exists(/usr/lib/libkrb5.a)
KRB5_HOME=	/usr
.endif
.endif

.if defined(KRB5_HOME) && !exists(${KRB5_HOME}/lib/libkrb5.a)
BROKEN=	KRB5_HOME is set but doesn\'t provide lib/libkrb5.a
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-gssapi=${KRB5_HOME}
.endif
.endif

.if ${PORT_OPTIONS:MNTLM}
CONFIGURE_ARGS+=	--enable-NTLM
PORTDOCS+=	README.NTLM
.endif

post-patch:
.if !exists(/usr/lib/libcom_err.so)
	@${REINPLACE_CMD} -e "s,-lcom_err,,g" ${WRKSRC}/configure
.endif

post-build:
	@${MAKE_CMD} -C ${WRKSRC} check

post-install:
	${INSTALL_DATA} ${FILESDIR}/fetchmailrc.sample \
		${STAGEDIR}${PREFIX}/etc/fetchmailrc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-X11-off:
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
