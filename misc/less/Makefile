# New ports collection makefile for:    less
# Version required:     3.21
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1996/11/11 05:49:42 obrien Exp $
#

DISTNAME=       less-321
CATEGORIES=	misc
MASTER_SITES=   ftp://prep.ai.mit.edu/pub/gnu/ ftp://ftp.uu.net/systems/gnu/

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes

EXTRA_PATCH=	patch-ab

pre-clean:
	@rm -f ${PATCHDIR}/${EXTRA_PATCH}

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
pre-patch:
	@echo "Making a colour version of less."
	@${CP} ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
.endif

.include <bsd.port.mk>
