# New ports collection makefile for:    elm
# Version required:     2.4.25.ME+.10
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.15 1996/02/26 00:57:03 ache Exp $
#

DISTNAME=       elm-2.4ME+10
CATEGORIES+=	mail
MASTER_SITES=   ftp://dionysos.fmi.fi/KEH/ \
		ftp://ftp.kiae.su/unix/mail/
WRKSRC=         ${WRKDIR}/elm2.4.ME+.10

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
