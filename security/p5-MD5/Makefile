# New ports collection makefile for:	p5-MD5
# Version required:			1.7
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:37:21 jfitz Exp $
#

DISTNAME=	MD5-1.7
PKGNAME=	p5-MD5-1.7
CATEGORIES+=	security
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/MD5/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/MD5/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/MD5/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/MD5/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/MD5/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/MD5/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ gzip -9nf ${PREFIX}/lib/perl5/man/man3/MD5.3
.endif

.include <bsd.port.mk>
