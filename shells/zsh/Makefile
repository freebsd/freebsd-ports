# New ports collection makefile for:	zsh
# Version required:     	2.6 beta13
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $Id: Makefile,v 1.15 1996/05/15 18:39:29 torstenb Exp $
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
.if !defined(NOMANCOMPRESS)
.for man in zsh zshbuiltins zshcompctl zshexpn zshmisc zshoptions \
	zshparam zshzle 
	gzip -9nf ${PREFIX}/man/man1/${man}.1
.endfor
.endif

.include <bsd.port.mk>
