# New ports collection makefile for:    elm
# Version required:     2.4 pl25 ME8b
# Date created:         26 June 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.13 1995/12/21 10:47:59 ache Exp $
#

DISTNAME=       elm-2.4pl24me8b
VERSION=        2.4.25m8b          # allows to not edit elm+* Makefiles
PKGNAME=        elm-${VERSION}
CATEGORIES+=	mail
MASTER_SITES=   ftp://ftp.kiae.su/unix/mail/ ftp://ftp.myxa.com/pub/elm/
DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} elm2.4.p25
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ache@FreeBSD.ORG

pre-patch:
	-patch -d ${WRKSRC} -s -p -N -S + < ${PORTSDIR}/distfiles/elm2.4.p25

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install

.include <bsd.port.mk>
