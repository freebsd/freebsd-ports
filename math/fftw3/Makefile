# New ports collection makefile for: fftw
# Version required:	2.0.1
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $Id$
#

DISTNAME=	fftw-2.0.1
CATEGORIES=	math
MASTER_SITES=	ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	Lars.Koeller@Uni-Bielefeled.DE

HAS_CONFIGURE=	YES

.include <bsd.port.mk>

.if ${ARCH} == "i386"
    CONFIGURE_ARGS= 	--enable-i386-hacks
.endif

CONFIGURE_ARGS+= 	--enable-shared

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	.for info in fftw.info
		install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
	.endfor
