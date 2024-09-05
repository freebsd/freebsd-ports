PORTNAME=	xen
PKGNAMESUFFIX=	-tools
DISTVERSION=	4.18.2.20240411
PORTREVISION=	2
CATEGORIES=	sysutils emulators

USE_GITLAB=	yes
GL_ACCOUNT=	xen-project
GL_TAGNAME=	2d38302c33b117aa9a417056db241aefc840c2f0
GL_TUPLE=	qemu-project:qemu:v8.0.4:qemu \
		qemu-project:dtc:b6910bec:dtc \
		qemu-project:meson:3a9b285a:meson \
		qemu-project:keycodemapdb:f5772a62:keycodemapdb \
		qemu-project:berkeley-testfloat-3:40619cbb:testfloat \
		qemu-project:berkeley-softfloat-3:b64af41c:softfloat

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen Hypervisor management tools
WWW=		https://www.xenproject.org/

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libyajl.so:devel/yajl \
		liblzo2.so:archivers/lzo2 \
		libpixman-1.so:x11/pixman \
		libargp.so:devel/argp-standalone \
		libxml2.so:textproc/libxml2
BUILD_DEPENDS=	seabios>0:misc/seabios \
		${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd:sysutils/edk2@xen_x64 \
		bash>0:shells/bash
RUN_DEPENDS=	seabios>0:misc/seabios \
		${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd:sysutils/edk2@xen_x64

OPTIONS_DEFINE=		DOCS SPICE
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

SPICE_DESC=		Enable SPICE protocol for QEMU
SPICE_CONFIGURE_WITH=	extra-qemuu-configure-args="--enable-spice"
SPICE_BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol
SPICE_LIB_DEPENDS=	libspice-server.so:devel/libspice-server

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64

USES=		cpe gettext gmake gnome libtool localbase:ldflags perl5 \
		pkgconfig python shebangfix iconv bison ninja:build
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
HAS_CONFIGURE=	yes
# Set ARCH=x86_64 in order to overwrite the environment ARCH=amd64
MAKE_ARGS=	clang=y ARCH=x86_64

BINARY_ALIAS=	python3=${PYTHON_CMD}

CONFIGURE_ARGS+=	--with-system-seabios=${LOCALBASE}/share/seabios/bios.bin \
			--with-system-ovmf=${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd \
			--mandir=${PREFIX}/share/man \
			--disable-golang

SHEBANG_FILES=	tools/misc/xencov_split \
		tools/python/scripts/convert-legacy-stream \
		tools/python/scripts/verify-stream-v2 \
		tools/xenmon/xenmon.py

ALL_TARGET=		tools
DOCS_ALL_TARGET=	docs
INSTALL_TARGET=		install-tools
DOCS_INSTALL_TARGET=	install-docs

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

post-extract:
	${MV} ${WRKSRC_qemu} ${WRKSRC}/tools/qemu-xen
	${RM} -rf ${WRKSRC}/tools/qemu-xen/dtc
	${MV} ${WRKSRC_dtc} ${WRKSRC}/tools/qemu-xen/dtc
	${RM} -rf ${WRKSRC}/tools/qemu-xen/meson
	${MV} ${WRKSRC_meson} ${WRKSRC}/tools/qemu-xen/meson
	${RM} -rf ${WRKSRC}/tools/qemu-xen/ui/keycodemapdb
	${MV} ${WRKSRC_keycodemapdb} ${WRKSRC}/tools/qemu-xen/ui/keycodemapdb
	${RM} -rf ${WRKSRC}/tools/qemu-xen/tests/fp/berkeley-testfloat-3
	${MV} ${WRKSRC_testfloat} ${WRKSRC}/tools/qemu-xen/tests/fp/berkeley-testfloat-3
	${RM} -rf ${WRKSRC}/tools/qemu-xen/tests/fp/berkeley-softfloat-3
	${MV} ${WRKSRC_softfloat} ${WRKSRC}/tools/qemu-xen/tests/fp/berkeley-softfloat-3

post-patch:
	@for p in `ls ${FILESDIR}/*qemuu*.patch 2>/dev/null`; do \
		${ECHO_CMD} "====> Applying $${p##*/}" ; \
		${PATCH} -s -p1 -i $${p} -d ${WRKSRC}/tools/qemu-xen ; \
	done

# The ports native 'build' target cannot be used because it sets CFLAGS, and
# that breaks the Xen kernel build system that's used by the tools in order to
# build the pv-shim.
do-build:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} ${MAKE_ARGS} ${INSTALL_TARGET}

post-install:
	${MKDIR} ${STAGEDIR}/var/run/xen

.include <bsd.port.mk>
