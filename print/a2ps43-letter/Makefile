# New ports collection makefile for:    a2ps
# Version required:     4.3
# Date created:         6 November 1994
# Whom:                 jmz & David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.7 1996/05/27 08:47:50 asami Exp $
#

DISTNAME=	a2ps
PKGNAME=	a2ps-${PAPERSIZE}-4.3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.imag.fr/archive/postscript/format.translators/
DISTFILES=	a2ps.V4.3.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS?=	WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f
NO_WRKSUBDIR=	yes
MAN1=		a2ps.1

letter::
	${MAKE} PAPERSIZE=letter

letter-install::
	${MAKE} PAPERSIZE=letter install

a4::
	${MAKE} PAPERSIZE=a4

a4-install::
	${MAKE} PAPERSIZE=a4 install


.if !defined(PAPERSIZE)
PAPERSIZE=a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
PAPERSIZE_UNSPECIFIED=	yes
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4 
PAPERSIZE=a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == LETTER
PAPERSIZE=letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.else
PAPERSIZE_INVALID= yes
.endif	# not defined PAPERSIZE


pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@echo "Defaulting to ${PAPERSIZE} sized paper."
	@echo ""
	@echo "Set the environment variable PAPERSIZE if you want to use other sizes."
	@echo "Possible values are:  A4 (default) or letter"
.elif defined(PAPERSIZE_INVALID)
	@echo "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\"" 
	@echo "Possible values are:  A4 (default) or letter"
	@/usr/bin/false
.endif

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man1
	@(cd ${WRKSRC}; make install.man)

post-install:
	strip ${PREFIX}/bin/a2ps

.include <bsd.port.mk>
