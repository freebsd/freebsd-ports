# $FreeBSD$

PORTNAME=	rumprun
DISTVERSION=	g20180105
CATEGORIES=	misc

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Unikernel and toolchain for various platforms

LICENSE=	BSD2CLAUSE

NOT_FOR_ARCHS=	aarch64 armv6 mips mips64 powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to FreeBSD on this architecture

USE_GCC=	any
USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_TUPLE=	rumpkernel:buildrump.sh:9c9b022:buildrump/buildrump.sh \
		rumpkernel:src-netbsd:b8b951e:src/src-netbsd
GH_TAGNAME=	8fe40c8

MANDIRS=	${PREFIX}/share/man

_BUILDRUMP_PROBE=${WRKSRC}/buildrump.sh/buildrump.sh probe

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} ./build-rr.sh -d ${PREFIX} -o objdir hw build

do-install:
	${SED} -i -e 's/^RRDEST=.*$$/RRDEST=\"${STAGEDIR:S/\//\\\//g}${PREFIX:S/\//\\\//g}\"/' ${WRKSRC}/objdir/config.sh
	cd ${WRKSRC}; ${SETENV} CC=${CC} ./build-rr.sh -o objdir hw install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-x86_64-hw/x86_64--netbsd-c++
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-x86_64-hw/x86_64--netbsd-gcc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-x86_64-hw/brprintmetainfo

.include <bsd.port.mk>
