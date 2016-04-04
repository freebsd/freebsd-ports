# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	OpenCA-PKCS7
PORTVERSION=	0.9.1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MADWOLF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for basic handling PKCS\#7 Signatures

BUILD_DEPENDS=	p5-OpenCA-OpenSSL>=0:security/p5-OpenCA-OpenSSL \
		p5-OpenCA-X509>=0:security/p5-OpenCA-X509 \
		p5-X500-DN>=0:net/p5-X500-DN
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.9.13

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
