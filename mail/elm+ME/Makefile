# New ports collection makefile for:    elm
# Version required:     2.4.25.ME+.14
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.20 1996/03/14 17:02:06 ache Exp $
#

DISTNAME=       elm-2.4ME+14
CATEGORIES+=	mail
MASTER_SITES=   ftp://dionysos.fmi.fi/KEH/ \
		ftp://ftp.kiae.su/unix/mail/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/elm2.4.ME+.14

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
