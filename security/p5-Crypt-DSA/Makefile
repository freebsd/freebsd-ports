# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-DSA
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DSA signature and key generation

RUN_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Convert-PEM>=0:converters/p5-Convert-PEM \
		p5-Data-Buffer>=0:misc/p5-Data-Buffer \
		p5-File-Which>=0.05:sysutils/p5-File-Which
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
