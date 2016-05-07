# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-PWSafe3
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	Read and write Passwordsafe v3 files

LICENSE=	ART20

BUILD_DEPENDS=	p5-Digest-HMAC>=1.00:security/p5-Digest-HMAC \
		p5-Crypt-CBC>=2.30:security/p5-Crypt-CBC \
		p5-Crypt-ECB>=1.45:security/p5-Crypt-ECB \
		p5-Crypt-Twofish>=2.14:security/p5-Crypt-Twofish \
		p5-Crypt-Random>=1.25:security/p5-Crypt-Random \
		p5-Data-UUID>=1.217:devel/p5-Data-UUID
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
