# New ports collection Makefile for:	RipMIME
# Date created:				16th March 2001
# Whom: 				Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ripmime
PORTVERSION=	1.3.2.0
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	jus@security.za.net
COMMENT=	Extracts attached files out of a MIME encoded email package

PLIST_FILES=	bin/ripmime
MAN1=		ripmime.1
USE_REINPLACE=	yes

pre-build:
	@${REINPLACE_CMD} -e 's!CC=!CC?=!; s!/usr/local!${PREFIX}!; \
		s!CFLAGS= -Wall -O2!CFLAGS+= -Wall!' \
		${WRKSRC}/Makefile

do_install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${MANPREFIX}/man/man1/ 

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
