# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Filter-Crypto
PORTVERSION=	2.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PAR-Packer>=0:devel/p5-PAR-Packer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

.include <bsd.port.mk>
