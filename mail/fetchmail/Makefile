# New ports collection makefile for:	fetchmail
# Version required:	1.8
# Date created:		13 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id $
#

DISTNAME=	fetchmail-1.8
CATEGORIES+=	mail
MASTER_SITES=	ftp://locke.ccil.org/pub/esr/

GNU_CONFIGURE=	yes

MAINTAINER=	ve@sci.fi

CONFIGURE_ENV+=	LDFLAGS="${CFLAGS}"

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/fetchmail.1
.endif

.include <bsd.port.mk>
