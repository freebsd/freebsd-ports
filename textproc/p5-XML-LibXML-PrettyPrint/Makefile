# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-LibXML-PrettyPrint
PORTVERSION=	0.003
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add pleasant whitespace to a DOM tree

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pragmatic>=0:${PORTSDIR}/devel/p5-Pragmatic \
		p5-XML-LibXML>=1.62:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0.20:${PORTSDIR}/devel/p5-Test-Warn

USE_PERL5=	configure
USES=		perl5

MAN3=		XML::LibXML::PrettyPrint.3

.include <bsd.port.mk>
