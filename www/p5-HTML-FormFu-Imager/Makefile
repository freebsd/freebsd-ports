# Created by: gugu
# $FreeBSD$

PORTNAME=	HTML-FormFu-Imager
PORTVERSION=	0.03006
PORTREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Imager.pm helpers for HTML::FormFu file uploads

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-FormFu>=0:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
