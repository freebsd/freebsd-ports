# $FreeBSD$

PORTNAME=	cadical
DISTVERSION=	1.0.3
DISTVERSIONSUFFIX=	-cb89cbf
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://fmv.jku.at/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple CDCL satisfiability solver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12_powerpc64=	fails to build: sed: 1: "s,@CXXFLAGS@,-O2 -pipe  ...": bad flag in substitute command: '-'

USES=		compiler:c++0x gmake tar:xz
GNU_CONFIGURE=	yes

CXXFLAGS+=	-fPIC

MAKEFILE=	makefile

BINARY_ALIAS=	make=${GMAKE}

EXES=		cadical mobical

PLIST_FILES=	${EXES:S/^/bin\//} \
		include/ccadical.h \
		lib/libcadical.a

do-install:
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/${e} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/ccadical.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
