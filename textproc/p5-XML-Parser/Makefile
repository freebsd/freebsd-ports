# New ports collection makefile for:	XML::Parser
# Version required:	2.19
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/11/14 19:44:34 kuriyama Exp $
#

DISTNAME=	XML-Parser-2.19
PKGNAME=	p5-XML-Parser-2.19
CATEGORIES=	textproc perl5
MASTER_SITES=	http://wwwx.netheaven.com/~coopercc/xmlparser/

MAINTAINER=	kuriyama@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
