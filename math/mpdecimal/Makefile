PORTNAME=	mpdecimal
DISTVERSION=	4.0.0
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
COMMENT=	C/C++ arbitrary precision decimal floating point libraries
WWW=		https://www.bytereef.org/mpdecimal/index.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

USES=		compiler:c++11-lang gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes
ALL_TARGET=	default
TEST_TARGET=	check_local

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS=	LD="${CC}" LDXX="${CXX}"
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec.so.${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec++.so.${DISTVERSION}

.include <bsd.port.post.mk>
