# Created by: Adrian Chadd
# $FreeBSD$

PORTNAME=	intel-pcm
PORTVERSION=	2.11
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/imp
DISTNAME=	IntelPerformanceCounterMonitor-V${PORTVERSION}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Intel PCM toolkit

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang gmake tar:xz

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/IntelPerformanceCounterMonitor-V${PORTVERSION}
MAKE_ARGS=	CXX="${CXX}" LIB=-lpthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*.x ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
