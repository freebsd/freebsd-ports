# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Filter-Crypto
PORTVERSION=	2.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

BUILD_DEPENDS=	p5-PAR-Packer>=0:${PORTSDIR}/devel/p5-PAR-Packer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

MAN1=		crypt_file.1
MAN3=		Filter::Crypto.3 Filter::Crypto::CryptFile.3 \
		Filter::Crypto::Decrypt.3 PAR::Filter::Crypto.3

NO_STAGE=	yes
.include <bsd.port.mk>
