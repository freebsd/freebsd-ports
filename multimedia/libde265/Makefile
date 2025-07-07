PORTNAME=	libde265
DISTVERSION=	1.0.12
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/strukturag/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source h.265 video codec
WWW=		https://www.libde265.org

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib cpe libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPE_VENDOR=	struktur

CONFIGURE_ARGS=	--disable-static --disable-sherlock265

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CONFIGURE_ENV+=	CCASFLAGS="${CFLAGS} -B${LOCALBASE}/bin -no-integrated-as"
LLD_UNSAFE=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libde265.so.0.1.5
	${MV} ${STAGEDIR}${PREFIX}/bin/dec265 \
		${STAGEDIR}${PREFIX}/bin/libde265-dec265

.include <bsd.port.post.mk>
