# New ports collection makefile for:	zsh
# Version required:     	2.6 beta7
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $Id: Makefile,v 1.9 1995/05/04 21:27:52 torstenb Exp $
#

DISTNAME=       zsh-2.6-beta8
PKGNAME=	zsh-2.6b8
CATEGORIES+=	shells
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/zsh/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/zsh.1 ${PREFIX}/man/man1/zshbuiltins.1 \
	${PREFIX}/man/man1/zshcompctl.1 ${PREFIX}/man/man1/zshexpn.1 \
	${PREFIX}/man/man1/zshmisc.1 ${PREFIX}/man/man1/zshoptions.1 \
	${PREFIX}/man/man1/zshparam.1 ${PREFIX}/man/man1/zshzle.1

.include <bsd.port.mk>
