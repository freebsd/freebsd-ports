# New ports collection makefile for:	screen
# Version required:     3.7.*
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.18 1997/09/15 20:09:01 ache Exp $
#

DISTNAME=       screen-3.7.6
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		screen.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/screen.info ${PREFIX}/info/dir

.include <bsd.port.mk>
