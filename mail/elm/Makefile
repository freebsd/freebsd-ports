# New ports collection makefile for:    elm
# See also: http://www.ozone.fmi.fi/KEH/
# Version required:     2.4ME
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.47 1998/08/22 13:20:35 asami Exp $
#

DISTNAME=       elm-2.4ME+43
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.ozone.fmi.fi/KEH/ \
		ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
		ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/elm2.4.ME+.43
MAN1=           answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 \
		frm.1 listalias.1 messages.1 newalias.1 newmail.1 \
		printmail.1 readmsg.1

HAS_CONFIGURE=  Yes
CONFIGURE_SCRIPT= Configure
CONFIGURE_ENV=  PREFIX="${PREFIX}"
CONFIGURE_ARGS= -S

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install
	if [ -f ${PREFIX}/lib/elm.mimetypes ] ; then \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib/elm.mimetypes-dist; \
	else \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib; \
	fi
.if defined(NOMANCOMPRESS)
	${LN} -f ${PREFIX}/man/man1/frm.1 ${PREFIX}/man/man1/nfrm.1
.else
	${LN} -sf ${PREFIX}/man/man1/frm.1.gz ${PREFIX}/man/man1/nfrm.1.gz
.endif

.include <bsd.port.mk>
