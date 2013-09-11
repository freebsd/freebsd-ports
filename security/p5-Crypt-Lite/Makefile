# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Lite
PORTVERSION=	0.82.11
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl extension for a symmetric data encryption and decryption

BUILD_DEPENDS=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::Lite.3

.include <bsd.port.mk>
