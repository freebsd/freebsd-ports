# New ports collection makefile for:	fetchmail
# Version required:     4.*
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id: Makefile,v 1.70 1998/12/07 17:54:31 billf Exp $
#
# NOTE:  The fetchmailconf program (an interactive program for
# writing .fetchmailrc files) requires Python, found in the Ports
# Collection under lang/python.  The fetchmail program itself
# does not need Python, so there is no RUN_DEPENDS for Python in
# this Makefile.

DISTNAME=       fetchmail-4.7.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-opie --enable-RPA --enable-POP2
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1
MLINKS=		fetchmail.1 fetchmailconf.1

.if exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4)
CONFIGURE_ARGS += --with-kerberos=/usr/include
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS += --with-kerberos5=${KRB5_HOME}
.endif

FDOC=   ${PREFIX}/share/doc/fetchmail

post-patch:
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

.include <bsd.port.mk>
