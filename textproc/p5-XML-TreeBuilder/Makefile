# New ports collection makefile for:	XML-TreeBuilder
# Date created:				Tue Jan  2 00:03:51 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	XML-TreeBuilder
PORTVERSION=	4.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl module to make XML document trees

BUILD_DEPENDS=	p5-HTML-Tagset>=3.02:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-Tree>=4.1:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cover>0:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Perl-Critic>0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Pod-Coverage>0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_MODBUILD=	yes

MAN3=		XML::TreeBuilder.3 XML::Element.3

.include <bsd.port.mk>
