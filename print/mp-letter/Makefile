# New ports collection makefile for:    mp
# Version required:     3.0.1
# Date created:         11 July 1996
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id: Makefile,v 1.1.1.1 1996/08/16 07:08:39 asami Exp $
#

DISTNAME=	mp-3.0.1
PKGNAME=	mp-${PAPERSIZE}-3.0.1
CATEGORIES=	print
MASTER_SITES=	ftp://nuxi.cs.ucdavis.edu/pub/misc/ \
		ftp://ftp.win.tue.nl/pub/mail/

MAINTAINER=	obrien@cs.ucdavis.edu

WRKSRC=		${WRKDIR}/mp
USE_GMAKE=	yes

.if !defined(PAPERSIZE)
PAPERSIZE=letter
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4
INSTALL_TARGET= install-a4
.endif

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

MP_UTILS=   digestp filep filofaxp franklinp mailp newsp timemanp timesysp
post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/mp.1
	-(cd ${PREFIX}/man/man1 ; \
	for mpu in $(MP_UTILS) ; do \
		ln -sf mp.1.gz $$mpu.1.gz ; done)
.else
	-(cd ${PREFIX}/man/man1 ; \
	for mp in $(MP_UTILS) ; do \
		ln -sf mp.1 $$mpu.1 ; done)

.endif

.include <bsd.port.mk>
