PORTNAME=	schemesh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Unix shell and Lisp REPL, fused together
WWW=		https://github.com/cosmos72/schemesh

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	chez-scheme:lang/chez-scheme
RUN_DEPENDS=	chez-scheme:lang/chez-scheme
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libuuid.so:misc/libuuid

USES=		gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	cosmos72
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PLIST_FILES=	bin/schemesh \
		bin/countdown \
		lib/schemesh/libschemesh_${DISTVERSION}.so

post-patch:
	@${REINPLACE_CMD} -e 's,chezscheme,chez-scheme,' \
		${WRKSRC}/utils/find_chez_scheme_dir.sh
	@${REINPLACE_CMD} -r -e 's/^CC=cc/CC=${CC}/' \
		-e 's,^(prefix.+)(=.+)$$,\1= ${PREFIX},' \
		-e '/^LDFLAGS/s|$$| ${LDFLAGS}|' \
		-e '/^CFLAGS/s|$$| ${CFLAGS}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
