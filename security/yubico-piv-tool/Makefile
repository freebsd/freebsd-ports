PORTNAME=	yubico-piv-tool
PORTVERSION=	2.7.2
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubico-piv-tool/Releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Yubico PIV tool
WWW=		https://developers.yubico.com/yubico-piv-tool/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/check.pc:devel/check \
		gengetopt:devel/gengetopt \
		help2man:misc/help2man
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		compiler cmake:noninja gmake pathfix pkgconfig ssl
USE_LDCONFIG=	yes
CMAKE_ARGS=	-D LIBCRYPTO_CFLAGS="-I${OPENSSLINC}" \
		-D LIBCRYPTO_LDFLAGS="-L${OPENSSLLIB} -lcrypto -L${LOCALBASE}/lib -pthread" \
		-D YKPIV_INSTALL_MAN_DIR="${LOCALBASE}/share/man" \
		-D YKPIV_INSTALL_PKGCONFIG_DIR="${LOCALBASE}/libdata/pkgconfig"

PLIST_FILES=	bin/yubico-piv-tool \
		include/ykpiv/ykpiv-config.h \
		include/ykpiv/ykpiv.h \
		lib/libykcs11.a \
		lib/libykcs11.so \
		lib/libykcs11.so.2 \
		lib/libykcs11.so.${PORTVERSION} \
		lib/libykpiv.a \
		lib/libykpiv.so \
		lib/libykpiv.so.2 \
		lib/libykpiv.so.${PORTVERSION} \
		libdata/pkgconfig/ykcs11.pc \
		libdata/pkgconfig/ykpiv.pc \
		share/man/man1/yubico-piv-tool.1.gz

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		${WRKSRC}/lib/ykpiv.c \
		${WRKSRC}/lib/util.c \
		${WRKSRC}/lib/internal.c \
		${WRKSRC}/tool/yubico-piv-tool.c
.endif

.include <bsd.port.post.mk>
