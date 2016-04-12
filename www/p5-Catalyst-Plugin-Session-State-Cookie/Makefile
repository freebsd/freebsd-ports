# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-State-Cookie
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Stores a Catalyst Session in a Cookie

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>=5.80005:www/p5-Catalyst-Runtime \
	p5-Catalyst-Plugin-Session>=0.27:www/p5-Catalyst-Plugin-Session \
	p5-MRO-Compat>=0:devel/p5-MRO-Compat \
	p5-Moose>0:devel/p5-Moose \
	p5-namespace-autoclean>0:devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure extract

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
