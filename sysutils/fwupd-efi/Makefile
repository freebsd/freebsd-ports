PORTNAME=	fwupd-efi
DISTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	EFI Application used by uefi-capsule plugin in fwupd
WWW=		https://fwupd.org/

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		${PYTHON_PKGNAMEPREFIX}pefile>0:devel/py-pefile@${PY_FLAVOR}

USES=		meson pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	fwupd

USE_GCC=	yes
SHEBANG_GLOB=	*.py

MESON_ARGS=	-Defi-includedir=${LOCALBASE}/include/efi \
		-Defi-ldsdir=${LOCALBASE}/lib \
		-Dgenpeimg=disabled \
		-Dpython=${PYTHON_CMD}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
FW_ARCH="x64"
.elif ${ARCH} == i386
FW_ARCH="ia32"
.else
FW_ARCH=${ARCH}
.endif

PLIST_FILES=	libdata/pkgconfig/fwupd-efi.pc \
		libexec/fwupd/efi/fwupd${FW_ARCH}.efi

post-patch:
	# use objcopy from binutils because GNU specific flags are used
	@${REINPLACE_CMD} "s|find_program('objcopy')|find_program('${LOCALBASE}/bin/objcopy')|g" \
		${WRKSRC}/meson.build

.include <bsd.port.post.mk>
