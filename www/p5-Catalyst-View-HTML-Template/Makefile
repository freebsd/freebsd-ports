# Created by: Gruen Christian <kiki@bsdro.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-HTML-Template
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kiki@bsdro.org
COMMENT=	HTML::Template view class for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5:www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:www/p5-Catalyst-Devel \
		p5-HTML-Template>0:www/p5-HTML-Template
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
