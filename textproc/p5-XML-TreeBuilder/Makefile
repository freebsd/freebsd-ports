# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-TreeBuilder
PORTVERSION=	5.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl module to make XML document trees

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tagset>=3.02:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-Tree>=4.1:${PORTSDIR}/www/p5-HTML-Tree \
		p5-XML-Catalog>=1.0.1:${PORTSDIR}/textproc/p5-XML-Catalog \
		p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cover>0:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
