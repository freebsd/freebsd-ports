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
PORTVERSION=	5.9.6
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.tuxedo.org/~esr/fetchmail/ \
		ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
.if defined(WITH_X11)
USE_PYTHON=	yes
RUN_DEPENDS=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

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
DOCS=		COPYING FAQ FEATURES NOTES README \
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
	@${PERL} -pi.bak -e 's|^#!/.*/python|#!${PREFIX}/bin/python|;' ${WRKSRC}/fetchmailconf
	@${SED} -e "s|@PREFIX@|${PREFIX}|" ${FILESDIR}/fetchmailconf > ${WRKDIR}/fetchmailconf

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${FDOC}
.endif
	${MV} ${PREFIX}/bin/fetchmailconf ${PREFIX}/libexec/fetchmailconf.bin
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin

.include <bsd.port.post.mk>
