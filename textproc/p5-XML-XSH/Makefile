# New ports collection makefile for:	XML::XSH
# Date created:		15 July 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-XSH
PORTVERSION=	1.8.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sourceforge/}
MASTER_SITE_SUBDIR=	XML/:cpan xsh/:sourceforge
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:cpan,sourceforge

MAINTAINER=	mat@FreeBSD.org
COMMENT=	This is xsh - an XML Editing Shell

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${SITE_PERL}/XML/LibXML/Iterator.pm:${PORTSDIR}/textproc/p5-XML-LibXML-Iterator \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/XML/XUpdate/LibXML.pm:${PORTSDIR}/textproc/p5-XML-XUpdate-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML/XPathContext.pm:${PORTSDIR}/textproc/p5-XML-LibXML-XPathContext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		xsh.1
MAN3=		XSH.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"requires perl 5.6.x or later. Install lang/perl5 and try again"
.endif

test: build
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
