PORTNAME=	highs
DISTVERSION=	g20210408
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for large scale sparse linear programming (LP) problems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libOsi.so:math/clp

USES=		blaslapack cmake compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ERGO-Code
GH_PROJECT=	HiGHS
GH_TAGNAME=	cfe064e

post-install: # see https://github.com/ERGO-Code/HiGHS/issues/502
	${RM} -r ${STAGEDIR}${PREFIX}/external

.include <bsd.port.mk>
