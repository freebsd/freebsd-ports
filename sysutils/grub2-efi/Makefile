# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2-efi
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU/grub
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Multiboot EFI boot loader

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/mformat:${PORTSDIR}/emulators/mtools \
		${LOCALBASE}/bin/grub-mkrescue:${PORTSDIR}/sysutils/grub2
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		help2man:${PORTSDIR}/misc/help2man

SSP_UNSAFE=	yes
USE_XZ=		yes
USE_GCC=	yes
USE_AUTOTOOLS=	automake aclocal autoconf
ACLOCAL_ARGS=	-Im4
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		bison gettext
ONLY_FOR_ARCHS=	amd64
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-platform=efi --disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

.include <bsd.port.pre.mk>

post-patch:
	@${LN} -s ${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 ${WRKSRC}/grub-core

do-install:
	@cd ${WRKSRC}/grub-core && gmake install DESTDIR=${STAGEDIR}

.include <bsd.port.post.mk>
