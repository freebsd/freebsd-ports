# New ports collection makefile for:	fetchmail
# Version required:	2.5.0
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $Id: Makefile,v 1.9 1996/12/21 11:13:04 max Exp $
#

DISTNAME=	fetchmail-2.5
PKGNAME=	fetchmail-2.5.0
CATEGORIES=	mail
MASTER_SITES=	ftp://locke.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1

.include <bsd.port.mk>
