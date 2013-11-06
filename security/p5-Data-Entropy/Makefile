# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Data-Entropy
PORTVERSION=	0.007
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Entropy (randomness) management

RUN_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Data-Float>=0.008:${PORTSDIR}/math/p5-Data-Float \
		p5-HTTP-Lite>=0.22:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-Params-Classify>=0:${PORTSDIR}/devel/p5-Params-Classify

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
