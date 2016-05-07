# $FreeBSD$

PORTNAME=	Facebook-Graph
PORTVERSION=	1.0801
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIZEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to integrate your apps with Facebook

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:devel/p5-Any-Moose \
	p5-AnyEvent-HTTP-LWP-UserAgent>=0.08:www/p5-AnyEvent-HTTP-LWP-UserAgent \
	p5-DateTime>=0.61:devel/p5-DateTime \
	p5-DateTime-Format-Strptime>=1.4000:devel/p5-DateTime-Format-Strptime \
	p5-JSON>=2.16:converters/p5-JSON \
	p5-MIME-Base64-URLSafe>=0.01:converters/p5-MIME-Base64-URLSafe \
	p5-Ouch>=0.0400:devel/p5-Ouch \
	p5-URI>=1.54:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
