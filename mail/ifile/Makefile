# New ports collection makefile for:	ifile
# Date created:         29 Jan 2002
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	ifile
PORTVERSION=	1.0.4
CATEGORIES=	mail textproc
MASTER_SITES=	http://www.ai.mit.edu/~jrennie/ifile/

MAINTAINER=	david+ports@bushong.net

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
.for file in argp-help.c strndup.c
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/argp/${file}
.endfor

.include <bsd.port.mk>
