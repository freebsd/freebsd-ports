# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	URI-FromHash
DISTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Create URI from hash of components

LICENSE=	ART20

BUILD_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI>=1.68:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
