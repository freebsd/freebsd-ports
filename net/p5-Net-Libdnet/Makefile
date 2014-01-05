# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Libdnet
PORTVERSION=	0.98
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Libdnet interface

BUILD_DEPENDS=	p5-Class-Gomor>=0:${PORTSDIR}/devel/p5-Class-Gomor
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include'

post-patch:
	@${REINPLACE_CMD} -e 's|dumbnet|dnet|g' ${WRKSRC}/Libdnet.xs

.include <bsd.port.mk>
