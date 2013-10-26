# Created by: sem@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2
PORTVERSION=	2.00
PORTREVISION=	2
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
USE_XZ=		yes
USE_GCC=	yes
USE_AUTOTOOLS=	automake aclocal autoconf
ACLOCAL_ARGS=	-Im4
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		bison gettext
ONLY_FOR_ARCHS=	i386 amd64
INFO=		grub grub-dev
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

OPTIONS_DEFINE=	MKFONT FUSE
MKFONT_DESC=	Build grub-mkfont (require freetype2)
FUSE_DESC=	Build grub-mount (require FUSE)

MAN1=		grub-editenv.1 grub-mklayout.1 grub-mkpasswd-pbkdf2.1 \
		grub-fstest.1 grub-script-check.1 grub-kbdcomp.1 \
		grub-mkstandalone.1 grub-mkrelpath.1 grub-mkrescue.1 \
		grub-menulst2cfg.1 grub-mkimage.1
MAN8=		grub-reboot.8 grub-set-default.8 grub-probe.8 \
		grub-mkconfig.8 grub-bios-setup.8 grub-mknetdir.8 \
		grub-install.8 grub-sparc64-setup.8 grub-ofpathname.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64"
EFIEMU=		"@comment "
.endif

PLIST_SUB+=	EFIEMU=${EFIEMU}

.if ${PORT_OPTIONS:MMKFONT}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu
MAN1+=		grub-mkfont.1
.else
MKFONT=		"@comment "
.endif

PLIST_SUB+=	MKFONT=${MKFONT}

.if ${PORT_OPTIONS:MFUSE}
LIB_DEPENDS+=	fuse:${PORTSDIR}/sysutils/fusefs-libs
CONFIGURE_ARGS+=	--enable-grub-mount
MAN1+=		grub-mount.1
.else
CONFIGURE_ARGS+=	--disable-grub-mount
FUSE=		"@comment "
.endif

PLIST_SUB+=	FUSE=${FUSE}

post-patch:
	@${LN} -s ${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 ${WRKSRC}/grub-core

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
