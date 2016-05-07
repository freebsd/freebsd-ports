# Created by: Alexandre Biancalana <ale@biancalanas.net>
# $FreeBSD$

PORTNAME=	Net-SMTPS
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ale@biancalanas.net
COMMENT=	SSL/STARTTLS support for Net::SMTP

RUN_DEPENDS=	p5-Authen-SASL>=2:security/p5-Authen-SASL \
		p5-IO-Socket-SSL>=1.9:security/p5-IO-Socket-SSL
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
