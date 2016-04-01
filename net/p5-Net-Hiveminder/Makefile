# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Hiveminder
PORTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to hiveminder.com

RUN_DEPENDS=	p5-Email-Simple>=0:mail/p5-Email-Simple \
		p5-Moose>=0:devel/p5-Moose \
		p5-Term-Encoding>=0:devel/p5-Term-Encoding \
		p5-Net-Jifty>=0:net/p5-Net-Jifty \
		p5-Number-RecordLocator>=0:converters/p5-Number-RecordLocator
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
