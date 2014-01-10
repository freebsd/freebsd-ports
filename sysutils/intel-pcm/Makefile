# Created by: Adrian Chadd
# $FreeBSD$

PORTNAME=	intel-pcm
PORTVERSION=	2.6
CATEGORIES=	sysutils

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	Intel PCM toolkit

LICENSE=	BSD4CLAUSE

USES=		gmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	erikarn
GH_COMMIT=	9b302ef
GH_TAGNAME=	${GH_COMMIT}

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}/src
MAKE_ARGS=	CC="${CXX}" OPT="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*.x ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
