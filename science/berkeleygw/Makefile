# $FreeBSD$

PORTNAME=	BerkeleyGW
DISTVERSION=	2.0.0
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	https://berkeley.box.com/shared/static/
DISTFILES=	wkqu37wu77tll53r8t1soe6ozqja67yy.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific program aimed at the ab initio virtual experimentation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		blaslapack:openblas gmake fortran python shebangfix
SHEBANG_GLOB=	*.sh *.py *awk

WRKSRC=		${WRKDIR}/BGW-${DISTVERSION}
BINARY_ALIAS=	make=${GMAKE} gcc=${CC}
MAKE_ARGS=	FREEBSD_GCC_DEFAULT=${GCC_DEFAULT} FREEBSD_PREFIX=${PREFIX} INSTDIR=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_MAKE_ARGS=	INSTALL_EXAMPLES=yes

PORTEXAMPLES=	*

post-patch:
	@${LN} -s ${WRKSRC}/config/generic.serial.freebsd.mk ${WRKSRC}/arch.mk
	@${LN} -s ${WRKSRC}/flavor_real.mk ${WRKSRC}/flavor.mk
	@${FIND} ${WRKSRC} -name "script*" -o -name "*.scr" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#! */bin/bash.*|#!/bin/sh|'

.include <bsd.port.mk>
