# New ports collection makefile for:    less
# Version required:     3.21
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.13 1996/11/17 09:06:02 obrien Exp $
#

DISTNAME=       less-321
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_GNU}

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
