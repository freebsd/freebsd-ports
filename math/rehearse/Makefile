# $FreeBSD$

PORTNAME=	rehearse
DISTVERSION=	g20190305
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Algebraic modeling library in C++ for linear optimization solvers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		depends on conflicting ports
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-08-26

LIB_DEPENDS=	libClp.so:math/clp \
		libOsi.so:math/osi

USES=		compiler:c++11-lang gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Rehearse
GH_TAGNAME=	31d12f8
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-stage:
	@${RM} -r ${STAGEDIR}${LOCALBASE}/share/coin

.include <bsd.port.mk>
