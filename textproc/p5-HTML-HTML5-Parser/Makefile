# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-HTML5-Parser
PORTVERSION=	0.301
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Named entity list for HTML parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-HTML5-Entities>=0.002:${PORTSDIR}/textproc/p5-HTML-HTML5-Entities \
		p5-IO-HTML>0:${PORTSDIR}/devel/p5-IO-HTML \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=1.94:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
