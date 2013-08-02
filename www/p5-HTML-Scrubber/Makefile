# Created by: Foxfair Hu <foxfair@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Scrubber
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for scrubbing/sanitizing html

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Scrubber.3

.include <bsd.port.mk>
