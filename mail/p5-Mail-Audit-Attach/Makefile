# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Audit-Attach
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mail::Audit plugin for attachment handling

RUN_DEPENDS=	p5-Mail-Audit>=2:mail/p5-Mail-Audit \
		p5-Mail-Tools>=1:mail/p5-Mail-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
