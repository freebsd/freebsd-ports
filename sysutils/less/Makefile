# New ports collection makefile for:    less
# Version required:     2.90
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.7 1995/04/08 13:54:29 ache Exp $
#

DISTNAME=       less-290
CATEGORIES+=	utilities
MASTER_SITES=   ftp://prep.ai.mit.edu/pub/gnu/ ftp://ftp.uu.net/systems/gnu/

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes

EXTRA_PATCH=	patch-ab

color:
	@echo "Okay, making a color version of less...."
	@cp ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
	@${MAKE} ${.MAKEFLAGS} all

pre-clean:
	@rm -f ${PATCHDIR}/${EXTRA_PATCH}

pre-patch:
	@if [ ! -f ${PATCHDIR}/${EXTRA_PATCH} ]; then \
	  echo '******************************************************' ; \
	  echo '* Note that you can build a color version of less by *' ; \
	  echo '* typing "make color" following a "make clean"       *' ; \
	  echo '******************************************************' ; \
	fi

.include <bsd.port.mk>
