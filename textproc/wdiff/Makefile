# New ports collection makefile for:	wdiff
# Version required:	0.5
# Date created:		Sep 15, 1997
# Whom:			Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.2 1999/01/27 07:41:28 fenner Exp $
#

DISTNAME=	wdiff-0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wdiff

MAINTAINER=	sanpei@yy.cs.keio.ac.jp

GNU_CONFIGURE=	yes

MAN1=		wdiff.1

post-install:
	@install-info ${PREFIX}/info/wdiff.info ${PREFIX}/info/dir

.include <bsd.port.mk>
