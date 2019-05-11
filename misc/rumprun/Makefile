# $FreeBSD$

PORTNAME=	rumprun
DISTVERSION=	g20180408
CATEGORIES=	misc

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Unikernel and toolchain for various platforms

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to FreeBSD on other architectures

USES=		gmake
USE_GCC=	any
USE_GITHUB=	yes
GH_ACCOUNT=	rumpkernel
GH_TUPLE=	rumpkernel:buildrump.sh:6cccd46:buildrump/buildrump.sh \
		rumpkernel:src-netbsd:b7a6451:src/src-netbsd
GH_TAGNAME=	085e6e0

PLIST_SUB=	ARCH=${RUMPARCH} ABI=${RUMPABI} I386="${RUMPARCH:Mx86_64:S/x86_64/@comment /}"

RUMPARCH=	${ARCH:S/amd64/x86_64/:S/i386/i486/}
RUMPABI=	${ARCH:S/amd64/netbsd/:S/i386/netbsdelf/}

do-build:
	# MAKE_ENV is not included here as buildrump.sh fails if certain
	# environmental variables like CFLAGS are set.
	cd ${BUILD_WRKSRC} && \
		${SETENV} CC=${CC} ./build-rr.sh -j ${MAKE_JOBS_NUMBER} -o objdir hw build

do-install:
	# Set the destination directory for the install target.
	${REINPLACE_CMD} -e 's|^RRDEST=.*$$|RRDEST=\"${STAGEDIR:S,/,\\/,g}${PREFIX:S,/,\\/,g}\"|' \
		${WRKSRC}/objdir/config.sh

	cd ${INSTALL_WRKSRC} && \
		${SETENV} CC=${CC} ./build-rr.sh -j ${MAKE_JOBS_NUMBER} -o objdir hw install

.for sec in 3 4 7
	${MV} ${STAGEDIR}${PREFIX}/share/man/man${sec} ${STAGEDIR}${PREFIX}/man
.endfor
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/${RUMPARCH}--${RUMPABI}-c++
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/${RUMPARCH}--${RUMPABI}-gcc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/rumprun-${RUMPARCH}-hw/brprintmetainfo

.include <bsd.port.mk>
