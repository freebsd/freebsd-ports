# New ports collection makefile for:    less
# Version required:     3.35
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.17 1999/01/27 07:41:23 fenner Exp $
#

DISTNAME=       less-335
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1

EXTRA_PATCH=	patch-ab

pre-clean:
	@${RM} -f ${PATCHDIR}/${EXTRA_PATCH}

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
pre-patch:
	@${ECHO_MSG} "Making a colour version of less."
	@${CP} ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
.endif

.include <bsd.port.mk>
