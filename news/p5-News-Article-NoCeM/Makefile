# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	News-Article-NoCeM
PORTVERSION=	0.08
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A module to generate accurate NoCeM notices

RUN_DEPENDS=	p5-News-Article>=0:${PORTSDIR}/news/p5-News-Article \
		p5-PGP-Sign>=0:${PORTSDIR}/security/p5-PGP-Sign
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
