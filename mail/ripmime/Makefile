# New ports collection Makefile for:	RipMIME
# Date created:				16th March 2001
# Whom: 				Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ripmime
PORTVERSION=	1.2.7
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	jus@security.za.net

pre-build:
	@${PERL} -pi -e 's!CC=!CC?=!; s!/usr/local!${PREFIX}!; \
		s!CFLAGS= -Wall -O2!CFLAGS+= -Wall!' \
		${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
