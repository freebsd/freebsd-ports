# $FreeBSD$

PORTNAME=	MetaPhysicL
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Metaprogramming, operator-overloaded classes for numerical simulations

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_GITHUB=	yes
GH_ACCOUNT=	roystgnr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-static

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmetaphysicl.so.0.0.0

.include <bsd.port.mk>
