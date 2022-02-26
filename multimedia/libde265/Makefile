# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	libde265
DISTVERSION=	1.0.8
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/strukturag/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/strukturag/${PORTNAME}/commit/
PATCHFILES=	900772c3e9ee1e106b93283fd8e7633d52899e40.patch:-p1 \
		7d5aeb5f11531de33f5b7ae0e768ffc50da4facb.patch:-p1 \
		dbff9077462899fc8e3b39907d43c2a6ad54e9f3.patch:-p1 \
		a3f1c6a0dea2b0d4a531255ad06ed40cdb184d25.patch:-p1 \
		4c0fe2c149c68ece57fde4cb11e05b5fb572da4b.patch:-p1

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open source h.265 video codec

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static --disable-sherlock265

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CONFIGURE_ENV+=	CCASFLAGS="${CFLAGS} -B${LOCALBASE}/bin -no-integrated-as"
LLD_UNSAFE=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libde265.so.0.1.1
	${MV} ${STAGEDIR}${PREFIX}/bin/dec265 \
		${STAGEDIR}${PREFIX}/bin/libde265-dec265

.include <bsd.port.post.mk>
