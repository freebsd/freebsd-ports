# Ports collection makefile for:	p5-Template-Extract
# Date created:			Nov 8, 2005
# Whom:	      			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Template-Extract
PORTVERSION=	0.40
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use TT2 syntax to extract data from documents

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	Template::Extract.3 \
	Template::Extract::Compile.3 \
	Template::Extract::Parser.3 \
	Template::Extract::Run.3

.include <bsd.port.mk>
