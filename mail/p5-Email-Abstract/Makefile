# $FreeBSD$

PORTNAME=	Email-Abstract
PORTVERSION=	3.006
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Unified interface to mail representations

RUN_DEPENDS=	p5-Email-Simple>=1.998:${PORTSDIR}/mail/p5-Email-Simple \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
