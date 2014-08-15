# $FreeBSD$

PORTNAME=	XML-Reader
PORTVERSION=	0.53
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading XML and providing path information based on a pull-parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Net-HTTP>=0:${PORTSDIR}/net/p5-Net-HTTP
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	PP
PP_DESC=	Use XML::Parsepp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPP}
RUN_DEPENDS+=	 p5-XML-Parsepp>=0.04:${PORTSDIR}/textproc/p5-XML-Parsepp
.else
RUN_DEPENDS+=	 p5-XML-Parser>=1:${PORTSDIR}/textproc/p5-XML-Parser
.endif

.include <bsd.port.mk>
