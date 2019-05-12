# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mprime
PORTVERSION=	29.8b3
CATEGORIES=	math benchmarks net
MASTER_SITES=	http://www.mersenne.org/ftp_root/gimps/ \
		ftp://mersenne.org/gimps/
DISTNAME=	p95v${PORTVERSION:R}${PORTVERSION:E}.source

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Great Internet Mersenne Prime Search

LICENSE=	EULA
LICENSE_NAME=	EULA
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl					\
		libhwloc.so:devel/hwloc					\
		libgmp.so:math/gmp

USES=		zip

NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makebsd
ALL_TARGET=	mprime
LLD_UNSAFE=	yes

SUB_FILES=	wrapper.sh

PLIST_FILES+=	bin/mprime bin/mprime-real

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
WRKSRC_SUBDIR=	linux64
.else
WRKSRC_SUBDIR=	linux
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
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
