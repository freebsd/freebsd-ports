# Created by: gugu
# $FreeBSD$

PORTNAME=	HTML-FormFu-Imager
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Imager.pm helpers for HTML::FormFu file uploads

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone>=0.31:${PORTSDIR}/devel/p5-Clone \
		p5-HTML-FormFu>=1:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
		p5-Moose>=1:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Attribute-Chained>=1.0.1:${PORTSDIR}/devel/p5-MooseX-Attribute-Chained
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
