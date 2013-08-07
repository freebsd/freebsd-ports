# $FreeBSD$

PORTNAME=	HTML-Quoted
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Extract structure of quoted HTML mail message

BUILD_DEPENDS=	p5-HTML-Parser>=3.0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Quoted.3

.include <bsd.port.mk>
