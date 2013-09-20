# Created by: Dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	Mojo-Server-FastCGI
PORTVERSION=	0.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARPI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Mojo Server FastCGI

LICENSE=	ART20

RUN_DEPENDS=	p5-Mojolicious>=3.21:${PORTSDIR}/www/p5-Mojolicious

USES=		perl5
USE_PERL5=	configure

MAN3=		Mojolicious::Command::fastcgi.3 \
		Mojo::Server::FastCGI.3

NO_STAGE=	yes
.include <bsd.port.mk>
