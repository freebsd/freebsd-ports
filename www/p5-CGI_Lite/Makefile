# New ports collection makefile for:	p5-CGI_Lite
# Version required:			1.7
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/06/24 18:43:07 jfitz Exp $
#

DISTNAME=	CGI_Lite-1.7
PKGNAME=	p5-CGI_Lite-1.7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		CGI_Lite.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
