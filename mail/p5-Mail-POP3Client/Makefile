# New ports collection makefile for:	p5-Mail-POP3Client
# Version required:			1.14
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:34 jfitz Exp $
#

DISTNAME=	POP3Client-1_14
PKGNAME=	p5-Mail-POP3Client-1.14
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Mail/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Mail/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Mail/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Mail/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Mail/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Mail/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Mail::POP3Client; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif     

.include <bsd.port.mk>
