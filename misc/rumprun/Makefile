# $FreeBSD$

PORTNAME=	rumprun
DISTVERSION=	g20180105
CATEGORIES=	misc

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Unikernel and toolchain for various platforms

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to FreeBSD on other architectures

USES=		gmake
USE_GCC=	any
USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_TUPLE=	rumpkernel:buildrump.sh:9c9b022:buildrump/buildrump.sh \
		rumpkernel:src-netbsd:b8b951e:src/src-netbsd
GH_TAGNAME=	8fe40c8

_BUILDRUMP_PROBE=${WRKSRC}/buildrump.sh/buildrump.sh probe
.include <bsd.port.options.mk>

RUMPARCH=	${ARCH:S/amd64/x86_64/:S/i386/i486/}
RUMPABI=	${ARCH:S/amd64/netbsd/:S/i386/netbsdelf/}
PLIST_SUB=	ARCH=${RUMPARCH} ABI=${RUMPABI}

.if ${RUMPARCH:Mi486}
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

do-build:
	cd ${WRKSRC}; ${SETENV} CC=${CC} ./build-rr.sh -d ${PREFIX} -o objdir hw build

do-install:
	${SED} -i -e 's/^RRDEST=.*$$/RRDEST=\"${STAGEDIR:S/\//\\\//g}${PREFIX:S/\//\\\//g}\"/' ${WRKSRC}/objdir/config.sh
	cd ${WRKSRC}; ${SETENV} CC=${CC} ./build-rr.sh -o objdir hw install
.for sec in 3 4 7
	${MV} ${STAGEDIR}${PREFIX}/share/man/man${sec} ${STAGEDIR}${PREFIX}/man
.endfor
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/${RUMPARCH}--${RUMPABI}-c++
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/${RUMPARCH}--${RUMPABI}-gcc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/brprintmetainfo

.include <bsd.port.mk>
