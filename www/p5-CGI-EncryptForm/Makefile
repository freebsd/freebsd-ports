# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	CGI-EncryptForm
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Implement trusted stateful CGI Form Data using cryptography

BUILD_DEPENDS=	p5-Crypt-HCE_SHA>=0:security/p5-Crypt-HCE_SHA \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
