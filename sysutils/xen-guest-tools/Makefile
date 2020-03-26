# Created by: Evan Sarmiento <esarmiento@wayfair.com>
# $FreeBSD$

PORTNAME=	xen-guest-tools
PORTVERSION=	4.13.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.xenproject.org/release/xen/${PORTVERSION}/
DISTNAME=	xen-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Xen tools within FreeBSD domU

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64 or i386
CONFLICTS=	xen-tools-[0-9]*

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/lib/libglib-2.0.so:devel/glib20 \
		${LOCALBASE}/lib/libargp.so:devel/argp-standalone \
		${LOCALBASE}/lib/libyajl.so:devel/yajl \
		${LOCALBASE}/lib/liblzo2.so:archivers/lzo2

USES=		bison gmake pkgconfig perl5 python:build \
		gettext-runtime:build gettext-tools:build
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-xen
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD} PYTHON_PATH=${PYTHON_CMD}
CONFIGURE_ENV+=	APPEND_LIB="${LOCALBASE}/lib"
CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	clang=y
MAKE_ENV+=	CC="${CC}"
MAKE_ENV+=	CFLAGS="${CFLAGS}"
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib
USE_LDCONFIG=	yes
PYTHON_NO_DEPENDS=	yes

PLIST_FILES=	bin/xen-detect \
		bin/xenstore \
		bin/xenstore-chmod \
		bin/xenstore-control \
		bin/xenstore-exists \
		bin/xenstore-list \
		bin/xenstore-ls \
		bin/xenstore-read \
		bin/xenstore-rm \
		bin/xenstore-watch \
		bin/xenstore-write \
		lib/libxenstore.so.3.0 \
		lib/libxentoolcore.so.1

post-patch:
	${REINPLACE_CMD} -e 's;86|x86_64;86no|x86_64no;' \
		${WRKSRC}/tools/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/misc/xen-detect \
		${WRKSRC}/tools/xenstore/xenstore \
		${WRKSRC}/tools/xenstore/xenstore-control \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/tools/xenstore/libxenstore.so.3.0 \
		${WRKSRC}/tools/libs/toolcore/libxentoolcore.so.1 \
		${STAGEDIR}${PREFIX}/lib/
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-chmod
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-control
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-exists
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-list
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-ls
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-read
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-rm
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-watch
	cd ${STAGEDIR}${PREFIX}/bin/ && ${LN} -f xenstore xenstore-write

.include <bsd.port.mk>
