# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-DateTime
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DateTime support for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-DateTime>=0:devel/p5-DateTime
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
