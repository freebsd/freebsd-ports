# New ports collection makefile for:	p5-Array-PrintCols
# Version required:			1.2
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:21:50 jfitz Exp $
#

DISTNAME=	Array-PrintCols-1.2
PKGNAME=	p5-Array-PrintCols-1.2
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Array/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Array/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Array/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Array/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Array/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Array/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/Array-PrintCols

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in ; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
