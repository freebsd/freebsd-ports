# $FreeBSD$

PORTNAME=	symmetrica
DISTVERSION=	2.0
CATEGORIES=	math
MASTER_SITES=	http://www.algorithm.uni-bayreuth.de/en/research/SYMMETRICA/
DISTFILES=	SYM2_0_tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of routines for combinatorial mathematics

LICENSE=	PD

USES=		gmake
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
