# New ports collection makefile for:    less
# Version required:     3.32
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.15 1996/11/18 14:06:45 asami Exp $
#

DISTNAME=       less-332
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

EXTRA_PATCH=	patch-ab

pre-clean:
	@rm -f ${PATCHDIR}/${EXTRA_PATCH}

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
pre-patch:
	@echo "Making a colour version of less."
	@${CP} ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
.endif

.include <bsd.port.mk>
