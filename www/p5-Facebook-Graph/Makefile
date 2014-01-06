# $FreeBSD$

PORTNAME=	Facebook-Graph
PORTVERSION=	1.0600
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIZEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to integrate your apps with Facebook

RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
	p5-AnyEvent-HTTP-LWP-UserAgent>=0.08:${PORTSDIR}/www/p5-AnyEvent-HTTP-LWP-UserAgent \
	p5-DateTime>=0.61:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-Strptime>=1.4000:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
	p5-JSON>=2.16:${PORTSDIR}/converters/p5-JSON \
	p5-MIME-Base64-URLSafe>=0.01:${PORTSDIR}/converters/p5-MIME-Base64-URLSafe \
	p5-Ouch>=0.0400:${PORTSDIR}/devel/p5-Ouch \
	p5-URI>=1.54:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
