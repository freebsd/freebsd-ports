# New ports collection makefile for:	p5-CGI
# Version required:			2.75
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:40:27 jfitz Exp $
#

DISTNAME=	CGI-modules-2.75
PKGNAME=	p5-CGI-2.75
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/CGI/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/CGI/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/CGI/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/CGI/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/CGI/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/CGI/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/URI/Escape.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:	
.if !defined(NOMANCOMPRESS)
		@ for file in CGI::Base.3 CGI::BasePlus.3 CGI::Carp.3 CGI::Form.3 CGI::MiniSvr.3 CGI::Request.3; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file; \
		done
.endif

.include <bsd.port.mk>
