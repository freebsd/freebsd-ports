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
PORTVERSION=	6.2.5
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.catb.org/~esr/%SUBDIR%/ \
		ftp://ftp.ayamura.org/pub/%SUBDIR%/ \
		ftp://ftp.win.jp/pub/%SUBDIR%/ \
		ftp://ftp.dti.ad.jp/pub/net/mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	fetchmail

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Batch mail retrieval utility for IMAP/POP2/POP3/APOP/KPOP/ETRN/ODMR

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext-old
.if defined(WITH_X11)
RUN_DEPENDS=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

.if defined(WITH_X11)
USE_PYTHON=	yes
.endif
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-opie --enable-RPA --enable-POP2 --enable-SDPS \
		--enable-nls --with-hesiod=no --enable-fallback=no
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"
MAKE_ENV+=	${CONFIGURE_ENV}
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

FDOC=		${PREFIX}/share/doc/fetchmail
DOCS=		FAQ FEATURES NEWS NOTES README \
		design-notes.html fetchmail-FAQ.html fetchmail-features.html

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=--enable-inet6
.endif

.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
CONFIGURE_ARGS+=--with-ssl=/usr
DOCS+=		README.SSL
PLIST_SUB+=	SSLDOCS="%%PORTDOCS%%"
.elif exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
CONFIGURE_ARGS+=-with-includes=${LOCALBASE}/include/openssl --with-ssl=${LOCALBASE}
CONFIGURE_ENV+=	RSAGLUE=-lRSAglue
DOCS+=		README.SSL
PLIST_SUB+=	SSLDOCS="%%PORTDOCS%%"
.else
PLIST_SUB+=	SSLDOCS="%%PORTDOCS%%@comment "
.endif

.if exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4)
CONFIGURE_ARGS += --with-kerberos=/usr
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS += --with-kerberos5=${KRB5_HOME}
.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS += --enable-NTLM
DOCS+=		README.NTLM
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%"
.else
PLIST_SUB+=	NTLMDOCS="%%PORTDOCS%%@comment "
.endif

pre-patch:
	@${CP} -f  /usr/include/md5.h ${WRKSRC}
	@${SED} -e "s,^#!/.*/python,#!${PREFIX}/bin/python,g" \
		${WRKSRC}/fetchmailconf > ${WRKDIR}/fetchmailconf.temp
	@${MV} -f ${WRKDIR}/fetchmailconf.temp ${WRKSRC}/fetchmailconf
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${FILESDIR}/fetchmailconf > ${WRKDIR}/fetchmailconf
	@${REINPLACE_CMD} -e "s,@l@,,;s,@GT_NO@,," \
		${WRKSRC}/intl/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${FDOC}
.endif
	${MV} ${PREFIX}/bin/fetchmailconf ${PREFIX}/libexec/fetchmailconf.bin
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin

.include <bsd.port.post.mk>
