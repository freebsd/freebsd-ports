# Created by: Tuc <freebsd-ports@t-b-o-h.net>
# $FreeBSD$

PORTNAME=	MIME-Lite-TT
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	TT enabled MIME::Lite wrapper

BUILD_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Test-Simple>=0:devel/p5-Test-Simple
RUN_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Test-Simple>=0:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
