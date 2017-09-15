# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-RSA
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to RSA encode and decode strings using OpenSSL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-Random>=0:security/p5-Crypt-OpenSSL-Random
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN_SSL=	openssl-devel

USES=		perl5 ssl
USE_PERL5=	configure
MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.mk>
