# New ports collection makefile for:	fetchmail
# Date created:		25 Feb 2000
# Whom:			Ville Eerola <ve@sci.fi>
#
# $FreeBSD$
#
# NOTE:  The fetchmailconf program (an interactive program for
# writing .fetchmailrc files) requires Python, Tk, X11, etc..
# The fetchmail program itself does not need Python, but if you
# want fetchmailconf to work, define WITH_X11

PORTNAME=	fetchmail
PORTVERSION=	6.3.11
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		http://homepages.uni-paderborn.de/mandree/fetchmail/:ma \
		http://mandree.home.pages.de/fetchmail/:ma \
		${MASTER_SITE_SUNSITE:S/$/:sunsite/}
MASTER_SITE_SUBDIR=	fetchmail/:DEFAULT \
			system/mail/pop/fetchmail/:sunsite \
			./:ma
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT,ma,sunsite

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_RC_SUBR=	fetchmail
FETCHMAILRC=	${PREFIX}/etc/fetchmailrc
SUB_FILES=	pkg-message

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-SDPS \
		--with-hesiod=no --enable-fallback=no PYTHON=:
# bsd.openssl.mk will add the LDFLAGS to CONFIGURE_ENV:
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ENV+=	${CONFIGURE_ENV}
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

OPTIONS=	X11	"Python/Tkinter dependencies for fetchmailconf" off \
		NLS	"National language support (NLS)."		on \
		NTLM	"Build in support for NTLM/MSN authentication." off \
		POP2	"Build pop2 support (obsolete)." off \
		GSSAPI	"Build GSSAPI support (requires KRB5_HOME to be set)" off

.include <bsd.port.options.mk>

.if defined(WITH_X11)
USE_PYTHON=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.include <bsd.port.pre.mk>

# Pop2 is obsolete
.if defined(WITH_POP2)
CONFIGURE_ARGS+=--enable-POP2
.endif

CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

DOCS=		FAQ FEATURES NEWS NOTES README README.SSL \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html \
		esrs-design-notes.html

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USE_GETTEXT=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS += --with-kerberos5=${KRB5_HOME}

.if defined(WITH_GSSAPI)
CONFIGURE_ARGS+=--with-gssapi=${KRB5_HOME}
.endif

.elif exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4)
CONFIGURE_ARGS += --with-kerberos=/usr

.if defined(WITH_GSSAPI)
CONFIGURE_ARGS+=--with-gssapi=/usr
.endif

.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS += --enable-NTLM
DOCS+=		README.NTLM
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%"
.else
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/bin/env python,#!${LOCALBASE}/bin/python,g" \
		${WRKSRC}/fetchmailconf.py
	@${CP} ${FILESDIR}/fetchmailconf ${WRKDIR}/fetchmailconf
	@${REINPLACE_CMD} -e "s,@LOCALBASE@,${LOCALBASE},g" \
		 ${WRKDIR}/fetchmailconf

pre-configure:

	@${ECHO_CMD} ""

.if defined(KRB5_HOME)
	@${ECHO_CMD} "Using Kerberos V support in ${KRB5_HOME}."
.else
	@${ECHO_CMD} "Use KRB5_HOME=<directory> to enable Kerberos V support in <directory> (usually /usr)."
.endif

.if defined(WITH_GSSAPI)
.if defined(KRB5_HOME)
	@${ECHO_CMD} "Enabling GSSAPI support in ${KRB5_HOME}."
.elif defined(MAKE_KERBEROS4)
.if exists(/usr/lib/libkrb.a)
	@${ECHO_CMD} "Enabling GSSAPI support in /usr."
.else
	@${ECHO_CMD} "Unable to detect Kerberos in your system. Disabling GSSAPI support."
.endif
.else
	@${ECHO_CMD} "GSSAPI requires Kerberos, but Kerberos is disabled."
.endif
.endif

	@${ECHO_CMD} ""

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${PREFIX}/libexec

	${INSTALL} -m 644 -o fetchmail -g fetchmail ${FILESDIR}/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc.sample
	if [ ! -f ${PREFIX}/etc/fetchmailrc ]; then \
		${CP} -p ${PREFIX}/etc/fetchmailrc.sample ${PREFIX}/etc/fetchmailrc ; \
		${CHMOD} 640 ${PREFIX}/etc/fetchmailrc ; \
	fi

	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
