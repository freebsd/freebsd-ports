# New ports collection makefile for:	zsh
# Version required:     	2.6 beta13
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $Id: Makefile,v 1.14 1996/03/06 17:57:37 torstenb Exp $
#

DISTNAME=       zsh-2.6-beta17
PKGNAME=	zsh-2.6b17
CATEGORIES+=	shells
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/zsh/src/ \
		ftp://ftp.sterling.com/zsh/src/ \
		ftp://ftp.rge.com/pub/zsh/src/ \
		ftp://ftp.cenatls.cena.dgac.fr/pub/shells/zsh/src/ \
		ftp://mrrl.lut.ac.uk/zsh/src/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/src/ \
		ftp://ftp.ips.oz.au/pub/packages/zsh/src/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/src/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/zsh.1 ${PREFIX}/man/man1/zshbuiltins.1 \
	${PREFIX}/man/man1/zshcompctl.1 ${PREFIX}/man/man1/zshexpn.1 \
	${PREFIX}/man/man1/zshmisc.1 ${PREFIX}/man/man1/zshoptions.1 \
	${PREFIX}/man/man1/zshparam.1 ${PREFIX}/man/man1/zshzle.1

.include <bsd.port.mk>
