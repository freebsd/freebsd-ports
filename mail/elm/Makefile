# New ports collection makefile for:    elm
# Version required:     2.4.25.ME+.11
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.16 1996/02/27 19:53:20 ache Exp $
#

DISTNAME=       elm-2.4ME+11
CATEGORIES+=	mail
MASTER_SITES=   ftp://dionysos.fmi.fi/KEH/ \
		ftp://ftp.kiae.su/unix/mail/
WRKSRC=         ${WRKDIR}/elm2.4.ME+.11

MAINTAINER=	ache@FreeBSD.ORG

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install
	if [ -f ${PREFIX}/lib/elm.mimetypes ] ; then \
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib/elm.mimetypes-dist; \
	else \
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib; \
	fi

.include <bsd.port.mk>
