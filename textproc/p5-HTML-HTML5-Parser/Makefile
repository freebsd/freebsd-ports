# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-HTML5-Parser
PORTVERSION=	0.301
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

PERL_CONFIGURE=	YES

MAN3=		HTML::HTML5::Parser.3 \
		HTML::HTML5::Parser::Error.3 \
		HTML::HTML5::Parser::UA.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-HTTP-Tiny>0:${PORTSDIR}/www/p5-HTTP-Tiny
RUN_DEPENDS+=	p5-HTTP-Tiny>0:${PORTSDIR}/www/p5-HTTP-Tiny
.endif

.include <bsd.port.post.mk>
