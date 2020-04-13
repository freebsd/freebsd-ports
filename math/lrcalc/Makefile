# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	lrcalc
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://sites.math.rutgers.edu/~asbuch/lrcalc/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Littlewood-Richardson Calculator

LICENSE=	GPLv2+

USES=		libtool

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INCL2FIX=	lrcalc.c maple.c schublib.h symfcn.c symfcn.h

TEST_TARGET=	check

pre-configure:
.for i in ${INCL2FIX}
	${REINPLACE_CMD} -e 's|<vectarg.h>|"vectarg.h"|;s|<vector.h>|"vector.h"|'	\
		-e 's|<hashtab.h>|"hashtab.h"|;s|<alloc.h>|"alloc.h"|' ${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
