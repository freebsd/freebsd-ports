# New ports collection makefile for:    elm
# See also: http://www.ozone.fmi.fi/KEH/
# Version required:     2.4.25.ME+28
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.30 1996/09/21 12:20:13 ache Exp $
#

DISTNAME=       elm-2.4ME+28
CATEGORIES+=	mail
MASTER_SITES=   ftp://dionysos.fmi.fi/KEH/ \
		ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
		ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/elm2.4.ME+.28

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install
	if [ -f ${PREFIX}/lib/elm.mimetypes ] ; then \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib/elm.mimetypes-dist; \
	else \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib; \
	fi

.include <bsd.port.mk>
