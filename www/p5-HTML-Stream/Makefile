# New ports collection makefile for:	p5-HTML-Stream
# Version required:			1.44
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.8 1997/09/14 02:54:43 jfitz Exp $
#

DISTNAME=	HTML-Stream-1.44
PKGNAME=	p5-HTML-Stream-1.44
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		HTML::Stream.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
