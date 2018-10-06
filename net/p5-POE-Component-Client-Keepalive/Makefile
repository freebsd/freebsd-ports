# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-Client-Keepalive
PORTVERSION=	0.2720
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for managing connections, with keep-alive

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-IP-Minimal>=0.02:net/p5-Net-IP-Minimal  \
		p5-POE>=1.311:devel/p5-POE \
		p5-POE-Component-Resolver>=0.917:dns/p5-POE-Component-Resolver

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
