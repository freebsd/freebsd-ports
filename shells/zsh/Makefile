# New ports collection makefile for:	zsh
# Version required:     	3.0.1
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $Id: Makefile,v 1.20 1996/09/14 22:54:58 torstenb Exp $
#

DISTNAME=       zsh-3.0.1
PKGNAME=	zsh-3.0.1
CATEGORIES+=	shells
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/zsh/ \
		ftp://ftp.sterling.com/zsh/ \
		ftp://ftp.rge.com/pub/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/pub/shells/zsh/ \
		ftp://mrrl.lut.ac.uk/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		ftp://ftp.ips.oz.au/pub/packages/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
.for man in zsh zshbuiltins zshcompctl zshexpn zshmisc zshoptions zshall \
	zshparam zshzle 
	gzip -9nf ${PREFIX}/man/man1/${man}.1
.endfor
.endif

.include <bsd.port.mk>
