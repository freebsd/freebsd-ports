# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Packet-Target
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	net perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Target object for all Net-Packet related stuff

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.Artistic

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Gomor>=1.00:devel/p5-Class-Gomor \
		p5-Net-Packet>=3.00:net/p5-Net-Packet

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
