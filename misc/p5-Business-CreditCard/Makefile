# New ports collection makefile for:	p5-Business-CreditCard
# Version required:			0.1
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1996/11/11 05:49:55 obrien Exp $
#

DISTNAME=	Business-CreditCard-0.1
PKGNAME=	p5-Business-CreditCard-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	YES

do-install:
		@ ${CP} ${WRKSRC}/CreditCard.pm ${WRKSRC}/CreditCard-0.1.pm
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/Business/
		@ ${INSTALL_DATA} ${WRKSRC}/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/Business/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/CreditCard.pm

.include <bsd.port.mk>
