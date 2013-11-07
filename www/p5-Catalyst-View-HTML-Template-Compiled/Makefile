# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Catalyst-View-HTML-Template-Compiled
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Template::Compiled View Class

BUILD_DEPENDS=	p5-HTML-Template-Compiled>=0.74:${PORTSDIR}/www/p5-HTML-Template-Compiled \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
