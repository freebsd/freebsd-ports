# Created by: Guerkan Karaman <gk.freebsd@googlemail.com>

PORTNAME=	ipxe
DISTVERSION=	g20220610
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Open source network boot firmware

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64/i386

BUILD_DEPENDS=	bash:shells/bash \
		syslinux:sysutils/syslinux

USES=		gmake perl5 shebangfix
USE_BINUTILS=	yes
USE_GCC=	yes:build
USE_GITHUB=	yes
GH_TAGNAME=	d3c8944d5c3ab262
USE_PERL5=	build
MAKE_ARGS=	AR=${AR} \
		ARCH=${ARCH:S/amd64/i386/} \
		AS=${AS} \
		CC=${CC} \
		HOST_CC=${CC} \
		LD=${LD} \
		NM=${NM} \
		NO_WERROR=1 \
		OBJCOPY=${OBJCOPY} \
		OBJDUMP=${OBJDUMP} \
		PERL=${PERL} \
		RANLIB=${RANLIB} \
		SIZE=${SIZE} \
		V=1

# Append user-settable build args from make.conf
MAKE_ARGS+=	${IPXE_MAKE_ARGS}
ALL_TARGET=	bin/ipxe.dsk bin/ipxe.lkrn bin/ipxe.pxe bin/ipxe.usb \
		bin/undionly.kpxe
# VMware ROMs
ALL_TARGET+=	bin/8086100f.mrom bin/808610d3.mrom bin/10222000.rom \
		bin/15ad07b0.rom
SUB_FILES=	pkg-message
WRKSRC_SUBDIR=	src
PLIST_FILES=	${ALL_TARGET:S@^bin/@${DATADIR}/@}

# Possible options are listed in ${WRKSRC}/config/*.h and
# http://ipxe.org/buildcfg.  Add a ! prefix to an option to undef it
# i.e. turn it off.
_IPXE_BUILDCFG=	branding:PRODUCT_NAME="${PKGNAME} (${OPSYS} ${OSREL}/${ARCH})" \
		console:CONSOLE_SERIAL \
		console:KEYBOARD_MAP=us \
		general:!DOWNLOAD_PROTO_FTP \
		general:DOWNLOAD_PROTO_HTTPS \
		general:DOWNLOAD_PROTO_NFS \
		general:IMAGE_TRUST_CMD \
		general:NET_PROTO_IPV6 \
		general:PING_CMD \
		general:POWEROFF_CMD

OPTIONS_DEFINE=		EFI ISO
OPTIONS_DEFAULT=	EFI ISO

EFI_DESC=	Create EFI images
ISO_DESC=	Create bootable CD image

EFI_BUILD_DEPENDS=	mformat:emulators/mtools
_EFI_ARCHS=		${ARCH:Mamd64:S/amd64/x86_64/} i386
_EFI_TARGETS=		ipxe snp snponly
.for _arch in ${_EFI_ARCHS}
. for _target in ${_EFI_TARGETS}
EFI_PLIST_FILES+=	${DATADIR}/${_target}.efi-${_arch}
. endfor
EFI_PLIST_FILES+=	${DATADIR}/ipxe.efi-${_arch}.usb
.endfor

ISO_BUILD_DEPENDS=	mkisofs:sysutils/cdrtools
ISO_MAKE_ARGS=		ISOLINUX_BIN="${WRKSRC}/isolinux.bin" \
			LDLINUX_C32="${LOCALBASE}/share/syslinux/bios/com32/elflink/ldlinux/ldlinux.c32"
ISO_ALL_TARGET=		bin/ipxe.iso

.include <bsd.port.pre.mk>

# Add user supplied build configuration after port options etc have
# been processed as they might want to overwrite some settings.
_IPXE_BUILDCFG+=	${IPXE_BUILDCFG}

# XXX: iPXE uses csplit when embedding certificates and assumes
# it's GNU csplit, so give it what it wants as a workaround if
# CERT=... is in {IPXE_,}MAKE_ARGS.
.if ${MAKE_ARGS:MCERT=*}
BUILD_DEPENDS+=	gcsplit:sysutils/coreutils
MAKE_ARGS+=	CSPLIT=gcsplit
.endif

do-configure:
.for _cat _opt in ${_IPXE_BUILDCFG:C/\:/ /}
	@${ECHO_CMD} '#undef ${_opt:S/^!//:C/(.*)=(.*)/\1/}' >> ${WRKSRC}/config/local/${_cat}.h
.if ${_opt:N!*}
	@${ECHO_CMD} '#define ${_opt:C/=/ /:S/^'//:S/'$//}' >> ${WRKSRC}/config/local/${_cat}.h
.endif
.endfor

pre-build-ISO-on:
# ISO creation fails if isolinux.bin is read only
	${INSTALL} -m 644 ${LOCALBASE}/share/syslinux/bios/core/isolinux.bin ${WRKSRC}/isolinux.bin

do-build-EFI-on:
.for _arch in ${_EFI_ARCHS}
	${DO_MAKE_BUILD} ARCH=${_arch} -C ${WRKSRC} ${_EFI_TARGETS:@.target.@bin-${_arch}-efi/${.target.}.efi@} \
		bin-${_arch}-efi/ipxe.usb
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${ALL_TARGET} ${STAGEDIR}${DATADIR}

do-install-EFI-on:
.for _arch in ${_EFI_ARCHS}
. for _target in ${_EFI_TARGETS}
	${INSTALL_DATA} ${WRKSRC}/bin-${_arch}-efi/${_target}.efi \
		${STAGEDIR}${DATADIR}/${_target}.efi-${_arch}
. endfor
	${INSTALL_DATA} ${WRKSRC}/bin-${_arch}-efi/ipxe.usb \
		${STAGEDIR}${DATADIR}/ipxe.efi-${_arch}.usb
.endfor

.include <bsd.port.post.mk>
