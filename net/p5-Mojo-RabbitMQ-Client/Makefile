# $FreeBSD$

PORTNAME=	Mojo-RabbitMQ-Client
PORTVERSION=	0.3.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SEBAPOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Mojo::IOLoop based RabbitMQ client

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Build>=0.4229:devel/p5-Module-Build \
  		p5-Module-Build-Tiny>=0.035:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-File-ShareDir>=1.116:devel/p5-File-ShareDir \
		p5-Net-AMQP>=0.06:net/p5-Net-AMQP \
		p5-Mojolicious>=7.53:www/p5-Mojolicious

USES=		pkgconfig perl5
USE_PERL5=	configure modbuild

.include <bsd.port.mk>
