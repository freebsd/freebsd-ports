# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-Filter-Chain
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Chains multiple Text::Filter objects and runs them in sequence

BUILD_DEPENDS=	p5-Text-Filter>=0:${PORTSDIR}/textproc/p5-Text-Filter

USES=		perl5
USE_PERL5=	configure

MAN3=		Text::Filter::Chain.3

NO_STAGE=	yes
.include <bsd.port.mk>
