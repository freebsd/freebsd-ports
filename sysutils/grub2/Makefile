# Created by: sem@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2
PORTVERSION=	2.00
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	GNU/grub
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiboot boot loader

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		help2man:${PORTSDIR}/misc/help2man

CONFLICTS=	grub-0*
SSP_UNSAFE=	yes
USE_GCC=	yes
USE_AUTOTOOLS=	automake aclocal autoconf
ACLOCAL_ARGS=	-Im4
GNU_CONFIGURE=	yes
USES=		bison gettext gmake tar:xz
ONLY_FOR_ARCHS=	i386 amd64
INFO=		grub grub-dev
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

OPTIONS_DEFINE=	MKFONT FUSE
OPTIONS_SUB=	yes
MKFONT_DESC=	Build grub-mkfont (require freetype2)
FUSE_DESC=	Build grub-mount (require FUSE)

MKFONT_CONFIGURE_ENABLE=	grub-mkfont
MKFONT_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2
MKFONT_BUILD_DEPENDS=		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

FUSE_CONFIGURE_ENABLE=		grub-mount
FUSE_LIB_DEPENDS=		libfuse.so:${PORTSDIR}/sysutils/fusefs-libs

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
PLIST_SUB+=	EFIEMU="@comment "
.else
PLIST_SUB+=	EFIEMU=""
.endif

post-patch:
	@${LN} -s ${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 \
		${WRKSRC}/grub-core

.include <bsd.port.post.mk>
