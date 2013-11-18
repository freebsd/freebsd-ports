# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	XML-Declare
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Create XML documents with declaration style

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
