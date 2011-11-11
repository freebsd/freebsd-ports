# New ports collection makefile for:	www/p5-Mojo-Server-FastCGI
# Date created:				13 Nov 2011
# Whom:					Dikshie <dikshie@sfc.wide.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	Mojo-Server-FastCGI
PORTVERSION=	0.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARPI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Mojo Server FastCGI

LICENSE=	ART20

RUN_DEPENDS=	p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious

PERL_CONFIGURE=	yes

MAN3=		Mojolicious::Command::fastcgi.3 \
		Mojo::Server::FastCGI.3

.include <bsd.port.mk>
