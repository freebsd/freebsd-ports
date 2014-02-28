# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Reader
PORTVERSION=	0.49
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading XML and providing path information based on a pull-parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp

OPTIONS_DEFINE=	PP
PP_DESC=	Use XML::Parsepp

USES=		perl5
USE_PERL5=	configure

PP_BUILD_DEPENDS=	p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
PP_BUILD_DEPENDS_OFF=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser
PP_RUN_DEPENDS=		p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
PP_RUN_DEPENDS_OFF=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser

.include <bsd.port.mk>
