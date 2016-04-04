# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WebService-BuzzurlAPI
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HOLLY
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Buzzurl WebService API

BUILD_DEPENDS=	p5-Class-Accessor>=0.25:devel/p5-Class-Accessor \
		p5-YAML-Syck>=0.21:textproc/p5-YAML-Syck \
		p5-libwww>=0:www/p5-libwww \
		p5-Readonly>=1.01:devel/p5-Readonly \
		p5-UNIVERSAL-require>=0.10:devel/p5-UNIVERSAL-require
RUN_DEPENDS=	p5-Class-Accessor>=0.25:devel/p5-Class-Accessor \
		p5-YAML-Syck>=0.21:textproc/p5-YAML-Syck \
		p5-libwww>=0:www/p5-libwww \
		p5-Readonly>=1.01:devel/p5-Readonly \
		p5-UNIVERSAL-require>=0.10:devel/p5-UNIVERSAL-require

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
