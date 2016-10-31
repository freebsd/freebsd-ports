# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DHCPClient
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of a DHCP client API

RUN_DEPENDS=	p5-Net-RawIP>=0:net/p5-Net-RawIP

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
