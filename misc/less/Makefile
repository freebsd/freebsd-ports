# New ports collection makefile for:    less
# Version required:     2.90
# Date created:         8 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1995/04/01 12:50:14 jkh Exp $
#

DISTNAME=       less-290
MASTER_SITES=   ftp://prep.ai.mit.edu/pub/gnu/ ftp://ftp.uu.net/systems/gnu/
CATEGORIES+=	utilities
GNU_CONFIGURE=	YES
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
