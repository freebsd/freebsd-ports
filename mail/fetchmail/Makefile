# New ports collection makefile for:	fetchmail
# Date created:		25 Feb 2000
# Whom:			Ville Eerola <ve@sci.fi>
#
# $FreeBSD$
#
# NOTE:  The fetchmailconf program (an interactive program for
# writing .fetchmailrc files) requires Python, found in the Ports
# Collection under lang/python.  The fetchmail program itself
# does not need Python, so there is no RUN_DEPENDS for Python in
# this Makefile.

PORTNAME=	fetchmail
PORTVERSION= 	5.3.8
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-OPIE --enable-RPA --enable-POP2 --enable-SDPS \
		--enable-nls
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=--enable-inet6
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
CONFIGURE_ARGS+=--with-ssl=/usr
.endif
.elif exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
CONFIGURE_ARGS+=-with-includes=${LOCALBASE}/include/openssl --with-ssl=${LOCALBASE}
.endif

.if exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4)
CONFIGURE_ARGS += --with-kerberos=/usr/include
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS += --with-kerberos5=${KRB5_HOME}
.endif

FDOC=   ${PREFIX}/share/doc/fetchmail

pre-patch:
	@${CP} -f  /usr/include/md5.h ${WRKSRC}
	@perl -pi.bak -e 's|^#!/.*/python|#!${PREFIX}/bin/python|;' ${WRKSRC}/fetchmailconf
	@${SED} -e "s|@PREFIX@|${PREFIX}|" ${FILESDIR}/fetchmailconf > ${WRKDIR}/fetchmailconf

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}
	${MV} ${PREFIX}/bin/fetchmailconf ${PREFIX}/libexec/fetchmailconf.bin
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${PREFIX}/bin

.include <bsd.port.post.mk>
