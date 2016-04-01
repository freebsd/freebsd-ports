# $FreeBSD$

PORTNAME=	Email-Address-Loose
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to make Email::Address->parse() loose

RUN_DEPENDS=	\
	p5-Email-Address>=1.88.9:mail/p5-Email-Address
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
