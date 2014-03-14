# Created by: Adrian Chadd
# $FreeBSD$

PORTNAME=	intel-pcm
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/imp
DISTNAME=	intelperformancecountermonitorv${PORTVERSION}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Intel PCM toolkit

LICENSE=	BSD3CLAUSE

USES=		gmake compiler:c++11-lang zip

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/IntelPerformanceCounterMonitorV${PORTVERSION}
MAKE_ARGS=	CC="${CXX}" OPT="${CXXFLAGS}" CXX="${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*.x ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
