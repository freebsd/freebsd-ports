# New ports collection makefile for:	p5-PGP
# Version required:			0.2alpha
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:38:35 jfitz Exp $
#

DISTNAME=	PGP-0.2alpha
PKGNAME=	p5-PGP-0.2a
CATEGORIES+=	security
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/PGP/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/PGP/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/PGP/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/PGP/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/PGP/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/PGP/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		pgp:${PORTSDIR}/security/pgp
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in PGP; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
