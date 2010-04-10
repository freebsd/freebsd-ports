# New ports collection makefile for:	XML-TokeParser
# Date created:		10 April 2010
# Whom:			Mike Bristow <mike@urgle.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Descent
PORTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mike@urgle.com
COMMENT=	Recursive descent XML parsing

BUILD_DEPENDS=	${SITE_PERL}/XML/TokeParser.pm:${PORTSDIR}/textproc/p5-XML-TokeParser \
		${SITE_PERL}/Test/Differences.pm:${PORTSDIR}/devel/p5-Test-Differences
RUN_DEPENDS=	${SITE_PERL}/XML/TokeParser.pm:${PORTSDIR}/textproc/p5-XML-TokeParser

PERL_CONFIGURE=	yes

MAN3=		XML::Descent.3

.include <bsd.port.mk>
