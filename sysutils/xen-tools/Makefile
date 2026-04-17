PORTNAME=	xen
PKGNAMESUFFIX=	-tools
DISTVERSION=	4.21.0.20260212
CATEGORIES=	sysutils emulators
DIST_SUBDIR=	xen/${PORTVERSION}

# Fetch from Gitlab so we can build from the stable branches and avoid having
# to manually pick up security fixes on top of the tarball.
USE_GITLAB=	yes
GL_ACCOUNT=	xen-project
GL_TAGNAME=	afaf4e7b503ad3e79602b39064e58d6488d10f3d

# Fetch QEMU from the release distribution files, building QEMU from git
# requires dealing with submodules and extra magic actions that cause pain when
# updating.  Any extra changes wanted for QEMU will be picked up as patches.
QEMU_VERSION=	9.1.0
MASTER_SITES+=	https://download.qemu.org/:qemu
DISTFILES+=	qemu-${QEMU_VERSION}.tar.xz:qemu

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen Hypervisor management tools
WWW=		https://www.xenproject.org/

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblzo2.so:archivers/lzo2 \
		libpixman-1.so:x11/pixman \
		libargp.so:devel/argp-standalone \
		libgnutls.so:security/gnutls \
		libinotify.so:devel/libinotify \
		libzstd.so:archivers/zstd \
		libfdt.so:sysutils/dtc
BUILD_DEPENDS=	seabios>0:misc/seabios \
		${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd:sysutils/edk2@xen_x64 \
		bash>0:shells/bash
RUN_DEPENDS=	seabios>0:misc/seabios \
		${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd:sysutils/edk2@xen_x64

OPTIONS_DEFINE=		DOCS SPICE
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

SPICE_DESC=		Enable SPICE protocol for QEMU
SPICE_BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol
SPICE_LIB_DEPENDS=	libspice-server.so:devel/libspice-server

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64

USES=		cpe gettext gmake gnome libtool localbase:ldflags perl5 \
		pkgconfig python shebangfix iconv bison ninja:build
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist distutils
HAS_CONFIGURE=	yes
# Set ARCH=x86_64 in order to overwrite the environment ARCH=amd64
MAKE_ARGS=	clang=y ARCH=x86_64

BINARY_ALIAS=	python3=${PYTHON_CMD}

CONFIGURE_ARGS+=	--with-system-seabios=${LOCALBASE}/share/seabios/bios.bin \
			--with-system-ovmf=${LOCALBASE}/share/edk2-xen/XEN_X64_EFI.fd \
			--mandir=${PREFIX}/share/man \
			--disable-golang \
			--with-extra-qemuu-configure-args="${QEMU_CONFIGURE_EXTRA}"

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

.if ${PORT_OPTIONS:MSPICE}
QEMU_CONFIGURE_EXTRA+=	--enable-spice
.endif
QEMU_CONFIGURE_EXTRA+=	--extra-ldflags=-L${LOCALBASE}/lib
QEMU_CONFIGURE_EXTRA+=	--extra-cflags=-I${LOCALBASE}/include
QEMU_CONFIGURE_EXTRA+=	--enable-fdt=system

post-extract:
	# Move QEMU into the directory expected by the build system
	${MV} ${WRKDIR}/qemu-${QEMU_VERSION} ${WRKSRC}/tools/qemu-xen

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
