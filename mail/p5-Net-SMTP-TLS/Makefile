# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-SMTP-TLS
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SMTP client supporting TLS and AUTH

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
