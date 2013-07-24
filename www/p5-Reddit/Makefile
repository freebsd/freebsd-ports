# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Reddit
PORTVERSION=	0.3.02.20120418
CATEGORIES=	www perl5
MASTER_SITES=	CRITICAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for interacting with Reddit

BUILD_DEPENDS=	p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-common-sense>=3.2:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-common-sense>=3.2:${PORTSDIR}/devel/p5-common-sense \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-HTTP-Cookies>=6:${PORTSDIR}/www/p5-HTTP-Cookies \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Reddit.3

.include <bsd.port.mk>
