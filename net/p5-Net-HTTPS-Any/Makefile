# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-HTTPS-Any
PORTVERSION=	0.12
CATEGORIES=	net perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple HTTPS class using whichever underlying SSL module is available

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-URI>=0:net/p5-URI \
		p5-Net-SSLeay>=1.30:security/p5-Net-SSLeay

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
