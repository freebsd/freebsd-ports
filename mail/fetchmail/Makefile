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
PORTVERSION=	6.3.2
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://download.berlios.de/%SUBDIR%/ \
		http://home.pages.de/~mandree/%SUBDIR%/ \
		http://home.leo.org/~barner/freebsd/distfiles/
MASTER_SITE_SUBDIR=	fetchmail

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Batch mail retrieval utility for IMAP/POP2/POP3/ETRN/ODMR

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root.crt:${PORTSDIR}/security/ca-roots

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-POP2 --enable-SDPS \
		--with-hesiod=no --enable-fallback=no
# bsd.openssl.mk will add the LDFLAGS to CONFIGURE_ENV:
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"
MAKE_ENV+=	${CONFIGURE_ENV}
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

.if defined(WITH_X11)
USE_PYTHON=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.include <bsd.port.pre.mk>

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
.elif exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4)
CONFIGURE_ARGS += --with-kerberos=/usr
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
.if defined(WITH_NTLM)
	@${ECHO_CMD} "Building in support for NTLM/MSN authentication."
.else
	@${ECHO_CMD} "Add -DWITH_NTLM to add support for NTLM/MSN authentication."
.endif
.if defined(WITH_X11)
	@${ECHO_CMD} "Adding Python/Tkinter dependencies for fetchmailconf."
.else
	@${ECHO_CMD} "Add -DWITH_X11 to add Python/Tkinter dependencies for fetchmailconf."
.endif
.if defined(WITHOUT_NLS)
	@${ECHO_CMD} "Using national language support (NLS)."
.else
	@${ECHO_CMD} "You can use -DWITHOUT_NLS to suppress national language support (NLS)."
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${PREFIX}/libexec

.include <bsd.port.post.mk>
