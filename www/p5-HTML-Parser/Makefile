# New ports collection makefile for:	p5-HTML-Parser
# Version required:			2.20
# Date Created:				28 April 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/06/24 15:56:17 vanilla Exp $
#

DISTNAME=	HTML-Parser-2.20
PKGNAME=	p5-HTML-Parser-2.20
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=	ports@FreeBSD.ORG

USE_PERL5=	yes

MAN3=		HTML::Entities.3 \
		HTML::Filter.3 \
		HTML::HeadParser.3 \
		HTML::LinkExtor.3 \
		HTML::Parser.3 \
		HTML::TokeParser.3

MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
