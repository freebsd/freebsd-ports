# $FreeBSD$

PORTNAME=	Email-MIME-Encodings
PORTVERSION=	1.314
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A unified interface to MIME encoding and decoding

RUN_DEPENDS=	p5-MIME-Base64>3.05:${PORTSDIR}/converters/p5-MIME-Base64
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Email::MIME::Encodings.3

.include <bsd.port.mk>
