# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Message
PORTVERSION=	3.009
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General message object

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-MIME-Types>=1.004:mail/p5-MIME-Types \
		p5-Mail-Tools>=2.17:mail/p5-Mail-Tools \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=1.23:net/p5-URI \
		p5-User-Identity>=0.94:devel/p5-User-Identity

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
