# New ports collection makefile for:    psutils
# Version required:     1.13
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.7 1995/11/22 13:18:23 asami Exp $
#

DISTNAME=	psutils-1.13
CATEGORIES+=	print
MASTER_SITES=	ftp://ftp.sunet.se/pub/text-processing/postscript/utilities/psutils/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		$(WRKDIR)/src-1.3

pre-install:
	@mkdir -p ${PREFIX}/share/psutils

post-install:
.if !defined(NOMANCOMPRESS)
	@for f in psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
	 getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 fixpspps.1 \
	 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 extractres.1 includeres.1; do \
	 gzip -nf ${PREFIX}/man/man1/$$f; done
.endif

.include <bsd.port.mk>
