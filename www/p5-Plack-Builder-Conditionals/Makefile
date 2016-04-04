# $FreeBSD$

PORTNAME=	Plack-Builder-Conditionals
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to extend Plack::Builder

RUN_DEPENDS=	\
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
	p5-Net-CIDR-Lite>0:net/p5-Net-CIDR-Lite \
	p5-Plack>=0.9941:www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
