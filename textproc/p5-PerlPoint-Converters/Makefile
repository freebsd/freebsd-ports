# New ports collection makefile for:	p5-PerlPoint-Converters
# Date created:		8 Jun 2004
# Whom:	      		mat
#
# $FreeBSD$
#

PORTNAME=	PerlPoint-Converters
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PerlPoint
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Convert PerlPoint docs into various formats

BUILD_DEPENDS=	${SITE_PERL}/PerlPoint/Parser.pm:${PORTSDIR}/textproc/p5-PerlPoint-Package \
		${SITE_PERL}/Getopt/ArgvFile.pm:${PORTSDIR}/devel/p5-Getopt-ArgvFile
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		pp2html.1 pp2latex.1
MAN3=		Bundle::PerlPoint.3 \
		PerlPoint::Converters.3 \
		PerlPoint::Tags::HTML.3 \
		PerlPoint::Tags::LaTeX.3

.if !defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}/doc; make

post-install:
	@cd ${WRKSRC}/doc; ${FIND} . | ${CPIO} -padm ${DOCSDIR}
.endif

.include <bsd.port.mk>
