# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Send
PORTVERSION=	2.199
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Email::Send - Simply Sending Email

BUILD_DEPENDS=	p5-Class-Accessor>=0.19:devel/p5-Class-Accessor \
		p5-Email-Address>=1.80:mail/p5-Email-Address \
		p5-Email-Simple>=1.92:mail/p5-Email-Simple \
		p5-Return-Value>=1.28:devel/p5-Return-Value \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
