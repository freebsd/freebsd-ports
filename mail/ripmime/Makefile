# New ports collection Makefile for:	RipMIME
# Date created:				16th March 2001
# Whom: 				Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ripmime
PORTVERSION=	1.0.0pr3
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	jus@security.za.net

pre-build:
	${PERL} -pi -e "s@/usr/bin/gcc@${CC}@g; \
			s@-Wall -O3 -m486@${CFLAGS}@g" ${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
