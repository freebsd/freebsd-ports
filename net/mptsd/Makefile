PORTNAME=	mptsd
DISTVERSIONPREFIX=v
DISTVERSION=	1.1-27
DISTVERSIONSUFFIX=-g21bf4ea
CATEGORIES=	net multimedia
MASTER_SITES=	https://georgi.unixsol.org/programs/mptsd/

MAINTAINER=	win2000rus@hotmail.com
COMMENT=	MPEG TS stream muxer

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

USES=		gmake tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	gfto
GH_PROJECT=	mptsd
GH_TUPLE=       gfto:libfuncs:0dc8d87080badd7a276316ad7ae6e6f1aed2331b:libfuncs/libfuncs \
	gfto:libtsfuncs:45e7e999a17c1954915295bd13b242bbd937cf28:libtsfuncs/libtsfuncs

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}*.conf ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
