# New ports collection makefile for:	screen
# Version required:     3.7.*
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       screen-3.7.6
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	screen

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		screen.1

post-install:
	@install-info ${PREFIX}/info/screen.info ${PREFIX}/info/dir

.include <bsd.port.mk>
