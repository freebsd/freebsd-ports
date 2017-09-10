# Created by: sem@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2
PORTVERSION=	2.00
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	GNU/grub
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiboot boot loader

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		help2man:misc/help2man

CONFLICTS=	grub-0*
SSP_UNSAFE=	yes
USE_GCC=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf bison cpe gettext gmake tar:xz
ONLY_FOR_ARCHS=	i386 amd64
INFO=		grub grub-dev
MAKE_JOBS_UNSAFE=	yes

CPE_PRODUCT=	grub
CPE_VENDOR=	gnu

CONFIGURE_ARGS=	--disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

OPTIONS_DEFINE=	MKFONT FUSE
OPTIONS_SUB=	yes
MKFONT_DESC=	Build grub-mkfont (require freetype2)
FUSE_DESC=	Build grub-mount (require FUSE)

MKFONT_CONFIGURE_ENABLE=	grub-mkfont
MKFONT_LIB_DEPENDS=		libfreetype.so:print/freetype2
MKFONT_BUILD_DEPENDS=		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

FUSE_CONFIGURE_ENABLE=		grub-mount
FUSE_LIB_DEPENDS=		libfuse.so:sysutils/fusefs-libs

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
PLIST_SUB+=	EFIEMU="@comment "
.else
PLIST_SUB+=	EFIEMU=""
.endif

post-patch:
	@${LN} -s ${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 \
		${WRKSRC}/grub-core

.include <bsd.port.post.mk>
