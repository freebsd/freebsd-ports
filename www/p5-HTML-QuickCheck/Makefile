# New ports collection makefile for:	p5-HTML-QuickCheck
# Version required:			1.0b1
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/05/24 13:17:15 jfitz Exp $
#

DISTNAME=	HTML-QuickCheck-1.0b1
PKGNAME=	p5-HTML-QuickCheck-1.0b1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		HTML::QuickCheck.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
