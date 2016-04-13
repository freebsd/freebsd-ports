# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.5.2
PORTREVISION=   3
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/
PKGNAMESUFFIX=	-tools

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Xen management tool, based on LibXenlight

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

BROKEN_FreeBSD_10=	does not build

LIB_DEPENDS=	libyajl.so:devel/yajl \
		liblzo2.so:archivers/lzo2 \
		libpixman-1.so:x11/pixman
BUILD_DEPENDS=	dev86>0:devel/dev86 \
		seabios>0:misc/seabios

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than amd64"

WRKSRC=		${WRKDIR}/xen-${PORTVERSION}

USES=		cpe gmake libtool perl5 pkgconfig python shebangfix localbase
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HOSTCC="${CC}" CC="${CC}" \
		ac_cv_path_BASH=${TRUE} \
		ac_cv_path_XGETTEXT=${TRUE}
MAKE_ARGS=	HOSTCC="${CC}" CC="${CC}" GCC="${CC}" cc="${GCC}" \
		HOSTCFLAGS="${CFLAGS}" SEABIOS_PATH="${LOCALBASE}/share/seabios/bios.bin"
QEMU_ARGS=	--disable-gtk \
		--disable-smartcard-nss \
		--disable-sdl \
		--disable-vte \
		--disable-glx \
		--disable-curses \
		--disable-tools \
		--disable-curl \
		--cxx=c++
CFLAGS=		-Wno-ignored-attributes -Qunused-arguments -Wno-header-guard \
		-Wno-tautological-compare -Wno-format-extra-args -w

EXTRA_PATCHES=	${FILESDIR}/0002-libxc-fix-xc_dom_load_elf_symtab.patch:-p1 \
		${FILESDIR}/xsa160-4.6.patch:-p1

CONFIGURE_ARGS+=	--with-extra-qemuu-configure-args="${QEMU_ARGS}"
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
	@for p in ${FILESDIR}/*qemuu*.patch; do \
		${ECHO_CMD} "====> Applying $${p##*/}" ; \
		${PATCH} -s -p1 -i $${p} -d ${WRKSRC}/tools/qemu-xen ; \
	done

post-install:
	${MKDIR} ${STAGEDIR}/var/run/xen

.include <bsd.port.mk>
