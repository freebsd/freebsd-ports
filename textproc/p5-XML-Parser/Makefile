# New ports collection makefile for:	XML::Parser
# Version required:	2.16
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	XML-Parser-2.16
PKGNAME=	p5-XML-Parser-2.16
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.netheaven.com/~coopercc/xmlparser/

MAINTAINER=	kuriyama@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
