# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-ECDSA
PORTVERSION=	0.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIKEM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL ECDSA

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-OpenSSL-EC>=0.05:security/p5-Crypt-OpenSSL-EC
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	5.18+ configure

.include <bsd.port.mk>
