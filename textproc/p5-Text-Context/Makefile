# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Context
PORTVERSION=	3.7
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handle highlighting search result context snippets

BUILD_DEPENDS=	p5-Text-Context-EitherSide>=1.1:${PORTSDIR}/textproc/p5-Text-Context-EitherSide \
		p5-UNIVERSAL-require>=0.03:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
