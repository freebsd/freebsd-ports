# New ports collection makefile for: fftw
# Version required:	2.1.1
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $Id: Makefile,v 1.1.1.1 1999/03/18 08:38:33 taoka Exp $
#

DISTNAME=	fftw-2.1.1
CATEGORIES=	math
MASTER_SITES=	ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/

MAINTAINER=	lkoeller@cc.fh-lippe.de

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if ${ARCH} == "i386"
CONFIGURE_ARGS=	--enable-i386-hacks
.endif
CONFIGURE_ARGS+=--enable-shared

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fftw
	${CP} ${WRKSRC}/doc/fftw.ps ${PREFIX}/share/doc/fftw
.endif

.include <bsd.port.post.mk>
