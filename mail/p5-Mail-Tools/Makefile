# New ports collection makefile for:	p5-Mail-Tools
# Version required:			1.06
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/11/10 21:32:12 obrien Exp $
#

DISTNAME=	MailTools-1.06
PKGNAME=	p5-Mail-Tools-1.06
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Mail::Address Mail::Cap Mail::Field Mail::Header Mail::Internet Mail::MIME Mail::Mailer Mail::Send Mail::Util; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif
		
.include <bsd.port.mk>
