PORTNAME=	mpdecimal
DISTVERSION=	4.0.1
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
COMMENT=	C/C++ arbitrary precision decimal floating point libraries
WWW=		https://www.bytereef.org/mpdecimal/index.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

USES=		compiler:c++11-lang gmake pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDXXFLAGS="${LDFLAGS}"
ALL_TARGET=	default
TEST_TARGET=	check_local

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec.so.${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec++.so.${DISTVERSION}

.include <bsd.port.mk>
