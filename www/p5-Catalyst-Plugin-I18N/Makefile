# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-I18N
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	I18N for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon \
		p5-Locale-Maketext-Simple>=0.19:devel/p5-Locale-Maketext-Simple \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
