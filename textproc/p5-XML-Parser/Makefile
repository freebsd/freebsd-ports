# New ports collection makefile for:	XML::Parser
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser
PORTVERSION= 	2.28
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://wwwx.netheaven.com/~coopercc/xmlparser/
MASTER_SITE_SUBDIR=	../by-authors/id/C/CO/COOPERCL
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org

USE_PERL5=	YES

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
