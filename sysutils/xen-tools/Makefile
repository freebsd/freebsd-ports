# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.5.1
PORTREVISION=	2
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/ \
		http://code.coreboot.org/p/seabios/downloads/get/:seabios
PKGNAMESUFFIX=	-tools

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Xen management tool, based on LibXenlight

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libyajl.so:${PORTSDIR}/devel/yajl \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libpixman-1.so:${PORTSDIR}/x11/pixman
BUILD_DEPENDS=	dev86>0:${PORTSDIR}/devel/dev86

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than amd64"

SEABIOSVERSION=	1.8.1
DISTFILES+=	${DISTNAME}.tar.gz \
		seabios-${SEABIOSVERSION}.tar.gz:seabios

WRKSRC=		${WRKDIR}/xen-${PORTVERSION}

USES=		cpe gmake libtool perl5 pkgconfig python shebangfix
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HOSTCC="${CC}" CC="${CC}" \
		ac_cv_path_BASH=${TRUE} \
		ac_cv_path_XGETTEXT=${TRUE}
MAKE_ARGS=	HOSTCC="${CC}" CC="${CC}" GCC="${GCC}" cc="${GCC}"
QEMU_ARGS=	--disable-gtk \
		--disable-smartcard-nss \
		--disable-sdl \
		--disable-vte \
		--disable-glx \
		--disable-curses \
		--disable-tools \
		--disable-curl \
		--cxx=c++

EXTRA_PATCHES=	${FILESDIR}/xsa137.patch:-p1 \
		${FILESDIR}/xsa142-4.5.patch:-p1 \
		${FILESDIR}/xsa153-libxl.patch:-p1 \
		${FILESDIR}/0002-libxc-fix-xc_dom_load_elf_symtab.patch:-p1

CONFIGURE_ARGS+=	--with-extra-qemuu-configure-args="${QEMU_ARGS}"
SHEBANG_FILES=	tools/misc/xencov_split \
		tools/misc/xen-ringwatch
USE_GCC=	yes
ALL_TARGET=	tools docs
INSTALL_TARGET=	install-tools install-docs

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

post-extract:
	${MV} ${WRKDIR}/seabios-${SEABIOSVERSION} ${WRKSRC}/tools/firmware/seabios-dir

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
