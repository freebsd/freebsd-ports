# New ports collection makefile for:	p5-Crypt-IDEA
# Version required:			1.0
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.9 1998/09/03 13:45:44 asami Exp $
#

DISTNAME=	Crypt-IDEA-1.0
PKGNAME=	p5-Crypt-IDEA-1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt

MAINTAINER=	jfitz@FreeBSD.ORG

BROKEN=		perl5 upgrade

USE_PERL5=	YES

MAN3=		Crypt::IDEA.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
