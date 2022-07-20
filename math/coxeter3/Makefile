PORTNAME=	coxeter
PORTVERSION=	3.1.20210124
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for the study of combinatorial aspects of Coxeter group theory

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	tscrim
GH_TAGNAME=	7b5a1f0

USES=		gmake

MAKEFILE=	makefile
.if !defined(WITH_DEBUG)
MAKE_ENV=	optimize=true
.endif
USE_LDCONFIG=	yes
TEST_TARGET=	check

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local/coxeter|${DATADIR}|'	\
		${WRKSRC}/directories.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/coxeter
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcoxeter3.so
	${MV} ${STAGEDIR}${PREFIX}/lib/libcoxeter3.so	\
		${STAGEDIR}${PREFIX}/lib/libcoxeter3.so.0
	${LN} -sf libcoxeter3.so.0 ${STAGEDIR}${PREFIX}/lib/libcoxeter3.so

.include <bsd.port.mk>
