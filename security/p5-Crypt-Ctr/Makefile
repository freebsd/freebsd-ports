# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Ctr
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl extension for encrypting data in Counter Mode

BUILD_DEPENDS=	p5-Crypt-CFB>=0:security/p5-Crypt-CFB
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
