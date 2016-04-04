# $FreeBSD$

PORTNAME=	HTML-Restrict
PORTVERSION=	2.2.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to strip unwanted HTML tags and attributes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Dump>0:devel/p5-Data-Dump \
	p5-HTML-Parser>0:www/p5-HTML-Parser \
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
	p5-Moo>=1.002000:devel/p5-Moo \
	p5-Type-Tiny>=1.000001:devel/p5-Type-Tiny \
	p5-URI>0:net/p5-URI \
	p5-namespace-clean>0:devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
