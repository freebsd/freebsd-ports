# New ports collection makefile for:	p5-HTML-Stream
# Version required:			1.24
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:46:17 jfitz Exp $
#

DISTNAME=	HTML-Stream-1.24
PKGNAME=	p5-HTML-Stream-1.24
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/HTML/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in HTML::Stream; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
