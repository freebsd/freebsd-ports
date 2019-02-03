# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	AnyEvent-Twitter
PORTVERSION=	0.64
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of the Twitter API for AnyEvent

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=5.34:devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=2.12:www/p5-AnyEvent-HTTP \
		p5-JSON>=2.53:converters/p5-JSON \
		p5-Net-OAuth>=0.27:net/p5-Net-OAuth \
		p5-URI>=1.58:net/p5-URI

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
