# New ports collection makefile for:    elm
# Version required:     2.4.25.ME+.19
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.24 1996/05/07 19:42:41 ache Exp $
#

DISTNAME=       elm-2.4ME+19
CATEGORIES+=	mail
MASTER_SITES=   ftp://dionysos.fmi.fi/KEH/ \
		ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
		ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/elm2.4.ME+.19

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
