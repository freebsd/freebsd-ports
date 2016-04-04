# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Email-Find
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Find RFC 822 email addresses in plain text

BUILD_DEPENDS=	p5-Email-Valid>=0:mail/p5-Email-Valid
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
