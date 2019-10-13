# $FreeBSD$

PORTNAME=	MetaPhysicL
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
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
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
