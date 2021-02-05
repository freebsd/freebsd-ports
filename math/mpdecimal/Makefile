# $FreeBSD$

PORTNAME=	mpdecimal
DISTVERSION=	2.5.1
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
COMMENT=	C/C++ arbitrary precision decimal floating point libraries

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	default
TEST_TARGET=	check_local

PORTDOCS=	libmpdec++/* libmpdec/*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec.so.${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpdec++.so.${DISTVERSION}

.include <bsd.port.mk>
