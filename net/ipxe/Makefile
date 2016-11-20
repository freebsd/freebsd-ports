# Created by: Guerkan Karaman <gk.freebsd@googlemail.com>
# $FreeBSD$

# With helpful hints from net/gpxe

PORTNAME=	ipxe
PORTVERSION=	20160213
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	t@tobik.me
COMMENT=	Open source network boot firmware

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/syslinux/bios/core/isolinux.bin:sysutils/syslinux \
		bash:shells/bash \
		mkisofs:sysutils/cdrtools

USE_GITHUB=	yes
GH_PROJECT=	ipxe
# iPXE hasn't had a release since 2010.
# See iPXE's FAQ at http://ipxe.org/faq
#
#   Q: Which version of iPXE should I use?
#
#   A: iPXE uses a rolling release model, in which every commit is intended
#      to be production-ready.  You should always use the latest code.
#
GH_TAGNAME=	7ecfe7159f94193a666200a17057d4cd5981b850

USES=		gmake perl5 shebangfix
USE_BINUTILS=	yes
USE_GCC=	yes
MAKE_ARGS=	PERL=${PERL} \
		CC=${CC} \
		HOST_CC=${CC} \
		OBJCOPY="${LOCALBASE}/bin/objcopy" \
		ISOLINUX_BIN="${WRKSRC}/isolinux.bin" \
		LDLINUX_C32="${LOCALBASE}/share/syslinux/bios/com32/elflink/ldlinux/ldlinux.c32"
WRKSRC_SUBDIR=	src
SHEBANG_FILES=	util/geniso util/gensdsk

PLIST_FILES=	%%DATADIR%%/ipxe.dsk \
		%%DATADIR%%/ipxe.usb \
		%%DATADIR%%/ipxe.iso \
		%%DATADIR%%/ipxe.pxe \
		%%DATADIR%%/ipxe.lkrn

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64/i386

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=i386
.endif

IPXE_EMBED?=	# Allows embedding of iPXE start scripts
.if ${IPXE_EMBED} != ""
MAKE_ARGS+=	EMBED="${IPXE_EMBED}"
.endif

IPXE_TRUST?=	# Path to the root certificates iPXE trusts
.if ${IPXE_TRUST} != ""
MAKE_ARGS+=	TRUST="${IPXE_TRUST}"
.endif

pre-everything::
	@${ECHO_MSG} "To build iPXE with an embedded script (path must be absolute):"
	@${ECHO_MSG} "make IPXE_EMBED=/path/to/ipxe/script install clean"
	@${ECHO_MSG}
	@${ECHO_MSG} "To build iPXE with new trusted root certificates"
	@${ECHO_MSG} "(see http://ipxe.org/crypto for more information):"
	@${ECHO_MSG} "make IPXE_TRUST=/path/to/ca1.crt,/path/to/ca2.crt"

pre-build:
# ISO creation fails if isolinux.bin is read only
	${INSTALL} -m 644 ${LOCALBASE}/share/syslinux/bios/core/isolinux.bin ${WRKSRC}/isolinux.bin

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ipxe.dsk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ipxe.usb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ipxe.iso ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ipxe.pxe ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ipxe.lkrn ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
