# New ports collection makefile for:    elm ME+ (unofficial Elm)
# Date created:         26 June 1995
# Whom:                 ache
#
# $FreeBSD$
#
# WARNING: it is NOT official Elm 2.*

PORTNAME=	elm
PORTVERSION=	2.4ME+77
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ozone.fmi.fi/KEH/ \
		ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
		ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=	ache@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/ME+/\.ME+\./}
MAN1=		answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 \
		frm.1 listalias.1 messages.1 newalias.1 newmail.1 \
		printmail.1 readmsg.1 elmcharset.1
MLINKS=		frm.1 nfrm.1	newmail.1 wnewmail.1

HAS_CONFIGURE=	Yes
CONFIGURE_SCRIPT= Configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
CONFIGURE_ARGS=	-S -d

post-install:
	perl -pi -e 's,/usr/local,${PREFIX},' ${WRKSRC}/nls/LANGS
	cd ${WRKSRC}/nls; ${MAKE} install
	if [ -f ${PREFIX}/lib/elm.mimetypes ] ; then \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib/elm.mimetypes-dist; \
	else \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib; \
	fi

.include <bsd.port.mk>
