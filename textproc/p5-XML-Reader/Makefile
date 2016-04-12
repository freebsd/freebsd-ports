# $FreeBSD$

PORTNAME=	XML-Reader
PORTVERSION=	0.65
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading XML and providing path information based on a pull-parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Acme-HTTP>=0:net/p5-Acme-HTTP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-Parsepp>=0:textproc/p5-XML-Parsepp

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	PP
PP_DESC=	Use Pure Perl XML Parser (instead of compiled)

PP_RUN_DEPENDS=		p5-XML-Parsepp>=0:textproc/p5-XML-Parsepp
PP_RUN_DEPENDS_OFF=	p5-XML-Parser>=0:textproc/p5-XML-Parser

.include <bsd.port.mk>
