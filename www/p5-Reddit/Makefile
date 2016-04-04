# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Reddit
PORTVERSION=	0.3.02.20120418
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	LOCAL/ehaupt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for interacting with Reddit

BUILD_DEPENDS=	p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Moose>=0:devel/p5-Moose \
		p5-ExtUtils-MakeMaker>=6.42:devel/p5-ExtUtils-MakeMaker \
		p5-common-sense>=3.2:devel/p5-common-sense
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-common-sense>=3.2:devel/p5-common-sense \
		p5-JSON>=2:converters/p5-JSON \
		p5-HTTP-Cookies>=6:www/p5-HTTP-Cookies \
		p5-libwww>=5.829:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
