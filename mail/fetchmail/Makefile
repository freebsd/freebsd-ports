# Created by: Ville Eerola <ve@sci.fi>
# $FreeBSD$
#
# NOTE:  The fetchmailconf program (an interactive program for
# writing .fetchmailrc files) requires Python, Tk, X11, etc..
#
# The fetchmail program itself does not need Python, but if you
# want fetchmailconf to work, define the X11 option.

PORTNAME=	fetchmail
PORTVERSION=	6.3.24
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/${PORTNAME}/branch_6.3/ \
		http://mandree.home.pages.de/${PORTNAME}/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

# Note USERS can only contain a single word as parts below rely on that.
USERS=	${PORTNAME}
GROUPS=	${USERS}

USE_RC_SUBR=	fetchmail
FETCHMAILRC=	${PREFIX}/etc/fetchmailrc
SUB_FILES=	pkg-message

USE_XZ=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--without-hesiod --enable-fallback=no \
		--with-ssl=${OPENSSLBASE}

LDFLAGS+=	-L${LOCALBASE}/lib
MAN1=	fetchmail.1
MLINKS=	fetchmail.1 fetchmailconf.1

OPTIONS_DEFINE=	X11 NLS NTLM GSSAPI
OPTIONS_DEFAULT=	GSSAPI
X11_DESC=	Python/Tkinter dependencies for ``fetchmailconf''
NTLM_DESC=	Build in support for NTLM/MSN authentication
GSSAPI_DESC=	Build GSSAPI/Kerberos 5 support

PORTDOCS=	FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

.include <bsd.port.options.mk>

# Pop2 is obsolete
.if defined(WITH_POP2)
CONFIGURE_ARGS+=	--enable-POP2
.endif

.if ${PORT_OPTIONS:MX11}
USE_PYTHON_RUN=	yes
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter
PLIST_SUB+=	X11="" NOX11="@comment "
.else
CONFIGURE_ARGS+=	PYTHON=:
SUB_FILES+=	fetchmailconf
PLIST_SUB+=	X11="@comment " NOX11=""
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
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

pre-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/bin/env python,#!${LOCALBASE}/bin/python,g" \
		${WRKSRC}/fetchmailconf.py

post-build:
	@${MAKE} -C ${WRKSRC} check

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if empty(PORT_OPTIONS:MX11)
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${PREFIX}/libexec
.endif
	${MKDIR} -m 0755 "/var/run/${PORTNAME}"
	${CHOWN} "${USERS}:${GROUPS}" "/var/run/${PORTNAME}"
	${INSTALL} -m 644 -o ${USERS} -g ${GROUPS} ${FILESDIR}/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc.sample
	if [ ! -f ${PREFIX}/etc/fetchmailrc ]; then \
		${CP} -p ${PREFIX}/etc/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc ; \
		${CHMOD} 600 ${PREFIX}/etc/fetchmailrc ; \
	fi

	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
