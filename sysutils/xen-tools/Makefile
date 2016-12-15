# $FreeBSD$

PORTNAME=	xen
PKGNAMESUFFIX=	-tools
PORTVERSION=	4.7.1
PORTREVISION=   1
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen management tool, based on LibXenlight

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

BROKEN_FreeBSD_9=	does not build
BROKEN_FreeBSD_10=	does not build

LIB_DEPENDS=	libyajl.so:devel/yajl \
		liblzo2.so:archivers/lzo2 \
		libpixman-1.so:x11/pixman \
		libargp.so:devel/argp-standalone
BUILD_DEPENDS=	dev86>0:devel/dev86 \
		seabios>0:misc/seabios \
		markdown>0:textproc/markdown

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than amd64"

USES=		cpe gettext gmake libtool localbase:ldflags perl5 pkgconfig \
		python shebangfix
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	clang=y
QEMU_ARGS=	--disable-gtk \
		--disable-smartcard-nss \
		--disable-sdl \
		--disable-vte \
		--disable-curses \
		--disable-tools \
		--disable-curl \
		--cxx=c++

EXTRA_PATCHES=	${FILESDIR}/var_paths.patch:-p1 \
		${FILESDIR}/xsa198.patch:-p1 \
		${FILESDIR}/0001-libxl-fix-creation-of-pkgconf-install-dir.patch \
		${FILESDIR}/0001-tools-configure-fix-pkg-config-install-path-for-Free.patch \
		${FILESDIR}/0001-libs-xenstore-set-correct-FreeBSD-device.patch

CONFIGURE_ARGS+=	--with-extra-qemuu-configure-args="${QEMU_ARGS}" \
			--with-system-seabios=${LOCALBASE}/share/seabios/bios.bin

# Disable bash and xgettext tests, they are not needed on FreeBSD.
CONFIGURE_ENV+=		ac_cv_path_BASH=${TRUE}

SHEBANG_FILES=	tools/misc/xencov_split \
		tools/misc/xen-ringwatch
ALL_TARGET=	tools docs
INSTALL_TARGET=	install-tools install-docs

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

post-patch:
	@${REINPLACE_CMD} "s,x86_64,amd64,g" ${WRKSRC}/tools/configure
	@${REINPLACE_CMD} -e "s,/var/lib,/var/db,g" \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/tools/libxc/include/xenguest.h \
		${WRKSRC}/tools/libxl/libxl_dom.c \
		${WRKSRC}/tools/libxl/libxl_dm.c \
		${WRKSRC}/tools/qemu-xen-traditional/i386-dm/helper2.c \
		${WRKSRC}/docs/man/*
	@for p in `ls ${FILESDIR}/*qemuu*.patch 2>/dev/null`; do \
		${ECHO_CMD} "====> Applying $${p##*/}" ; \
		${PATCH} -s -p1 -i $${p} -d ${WRKSRC}/tools/qemu-xen ; \
	done

post-install:
	${MKDIR} ${STAGEDIR}/var/run/xen

.include <bsd.port.mk>
