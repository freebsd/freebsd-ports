# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	HTML-Template-Expr
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to use HTML Templates which allows expressions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=    p5-HTML-Template>=2.4:${PORTSDIR}/www/p5-HTML-Template \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS=  ${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
