# New ports collection makefile for:	XML::Parser
# Version required:	2.27
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	XML-Parser-2.27
PKGNAME=	p5-XML-Parser-2.27
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://wwwx.netheaven.com/~coopercc/xmlparser/
MASTER_SITE_SUBDIR=	../by-authors/id/C/CO/COOPERCL

MAINTAINER=	kuriyama@FreeBSD.org

USE_PERL5=	YES

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	@cd ${WRKSRC}/Expat/expat; ${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Expat/expat/xmlwf/xmlwf ${PREFIX}/bin/

.include <bsd.port.mk>
