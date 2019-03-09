# Created by: Guerkan Karaman <gk.freebsd@googlemail.com>
# $FreeBSD$

PORTNAME=	ipxe
PORTVERSION=	20190307
CATEGORIES=	net

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Open source network boot firmware

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64/i386

USES=		gmake perl5 shebangfix
USE_BINUTILS=	yes
USE_GCC=	yes
USE_GITHUB=	yes
# iPXE hasn't had a release since 2010.
# See iPXE's FAQ at http://ipxe.org/faq
#
#   Q: Which version of iPXE should I use?
#
#   A: iPXE uses a rolling release model, in which every commit is intended
#      to be production-ready.  You should always use the latest code.
#
GH_TAGNAME=	b28ccfc725c9a52401aaa09de0734a44bd44a02d
USE_PERL5=	build

ALL_TARGET=	bin/ipxe.dsk bin/ipxe.lkrn bin/ipxe.pxe bin/ipxe.usb bin/undionly.kpxe
# VMware ROMs
ALL_TARGET+=	bin/8086100f.mrom bin/808610d3.mrom bin/10222000.rom bin/15ad07b0.rom
MAKE_ARGS=	HOST_CC=${CC} \
		PERL=${PERL} \
		CC=${CC} \
		AS=${AS} \
		LD=${LD} \
		SIZE=${SIZE} \
		AR=${AR} \
		RANLIB=${RANLIB} \
		OBJCOPY=${OBJCOPY} \
		NM=${NM} \
		OBJDUMP=${OBJDUMP} \
		ARCH=${ARCH:S/amd64/i386/} \
		NO_WERROR=1 \
		V=1 \
		${IPXE_MAKE_ARGS}
PLIST_FILES=	${ALL_TARGET:S@^bin/@${DATADIR}/@}
SHEBANG_FILES=	util/geniso util/gensdsk
SUB_FILES=	pkg-message
WRKSRC_SUBDIR=	src

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

OPTIONS_DEFAULT=	ISO EFI
OPTIONS_DEFINE=		ISO EFI

EFI_DESC=	Create EFI image
ISO_DESC=	Create bootable CD image

EFI_ARCHS=	i386 ${ARCH:Mamd64:S/amd64/x86_64/}
.for _arch in ${EFI_ARCHS}
EFI_PLIST_FILES+=	${DATADIR}/ipxe.efi-${_arch}
.endfor

ISO_ALL_TARGET=	bin/ipxe.iso
ISO_BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/share/syslinux/bios/core/isolinux.bin:sysutils/syslinux \
		mkisofs:sysutils/cdrtools
ISO_MAKE_ARGS=	ISOLINUX_BIN="${WRKSRC}/isolinux.bin" \
		LDLINUX_C32="${LOCALBASE}/share/syslinux/bios/com32/elflink/ldlinux/ldlinux.c32"

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
.for _arch in ${EFI_ARCHS}
	${DO_MAKE_BUILD} ARCH=${_arch} -C ${WRKSRC} bin-${_arch}-efi/ipxe.efi
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${ALL_TARGET} ${STAGEDIR}${DATADIR}

do-install-EFI-on:
.for _arch in ${EFI_ARCHS}
	${INSTALL_DATA} ${WRKSRC}/bin-${_arch}-efi/ipxe.efi ${STAGEDIR}${DATADIR}/ipxe.efi-${_arch}
.endfor

.include <bsd.port.post.mk>

RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
