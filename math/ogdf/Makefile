# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogdf
PORTVERSION=	2020.02
CATEGORIES=	math
MASTER_SITES=	https://ogdf.uos.de/wp-content/uploads/2020/02/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	C++ class library for the automatic layout of diagrams

LICENSE=		GPLv2 GPLv3
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL_v2.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE_GPL_v3.txt

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	fails to compile: reports "include/cpuid.h:11:2: this header is for x86 only"

CONFLICTS_INSTALL=	CoinMP-[0-9]*

USES=		cmake compiler:c++11-lang zip
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DEXAMPLES_INSTALL_DIR:PATH=${EXAMPLESDIR_REL}

WRKSRC=		${WRKDIR}/${PORTNAME:tu}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/ogdf/lib/minisat/doc

.include <bsd.port.mk>
