# New ports collection makefile for:	p5-Mail-Tools
# Version required:			1.06
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/04/20 13:52:35 wosch Exp $
#

DISTNAME=	MailTools-1.09
PKGNAME=	p5-Mail-Tools-1.09
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Mail::Address.3 Mail::Cap.3 Mail::Field.3 Mail::Header.3 \
		Mail::Internet.3 Mail::Alias.3 Mail::Mailer.3 Mail::Send.3 \
		Mail::Util.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
