# New ports collection makefile for:	p5-Crypt-DES
# Version required:			1.0
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:33:53 jfitz Exp $
#

DISTNAME=	Crypt-DES-1.0
PKGNAME=	p5-Crypt-DES-1.0
CATEGORIES+=	security
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Crypt/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Crypt/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Crypt/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Crypt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Crypt/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Crypt/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Crypt::DES; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
