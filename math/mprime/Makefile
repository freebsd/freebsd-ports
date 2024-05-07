PORTNAME=	mprime
PORTVERSION=	30.19b14
CATEGORIES=	math benchmarks net
MASTER_SITES=	https://www.mersenne.org/download/software/v${PORTVERSION:R}/${PORTVERSION:R}.19/
DISTNAME=	p95v${PORTVERSION:R}${PORTVERSION:E}.source

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Great Internet Mersenne Prime Search
WWW=		https://www.mersenne.org/

LICENSE=	EULA
LICENSE_NAME=	EULA
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN_i386=    /gwnum/polymult.a missed in /linux/makebsd
ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl					\
		libhwloc.so.15:devel/hwloc2				\
		libgmp.so:math/gmp

USES=		localbase zip
MAKEFILE=	makebsd
ALL_TARGET=	mprime
LLD_UNSAFE=	yes

SUB_FILES=	pkg-message wrapper.sh

NO_WRKSUBDIR=	yes
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PKGMESSAGE=	${WRKSRC}/pkg-message
PLIST_FILES+=	bin/mprime bin/mprime-real

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
WRKSRC_SUBDIR=	linux64
.else
WRKSRC_SUBDIR=	linux
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|CC = .*||g" \
		-e "s|CXX = .*||g" \
		-e "s|-Wl,-M||g" \
		-e "s|CFLAGS = |CFLAGS += |g" \
		-e "s|CXXFLAGS = |CXXFLAGS += |g" \
		${PATCH_WRKSRC}/gwnum/makebsd64 \
		${PATCH_WRKSRC}/gwnum/makemsys \
		${PATCH_WRKSRC}/linux64/makebsd \
		${PATCH_WRKSRC}/linux/makebsd

pre-build:
.if ${ARCH} == "amd64"
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${PATCH_WRKSRC}/gwnum ${MAKE_FLAGS} makebsd64 ${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g}
.elif ${ARCH} == "i386"
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${PATCH_WRKSRC}/gwnum ${MAKE_FLAGS} makemsys ${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${STAGEDIR}${PREFIX}/bin/mprime-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/mprime

.include <bsd.port.post.mk>
