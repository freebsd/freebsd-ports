PORTNAME=	grub2-efi
PORTVERSION=	2.02
PORTREVISION=	20
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/kevlo
DISTNAME=	grub-${PORTVERSION}_7

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Multiboot EFI boot loader

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/mformat:emulators/mtools \
		${LOCALBASE}/bin/grub-mkrescue:sysutils/grub2-pcbsd
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/bin/bash:shells/bash \
		help2man:misc/help2man

ONLY_FOR_ARCHS=	amd64
USES=		autoreconf:build bison cpe gettext gmake python tar:xz

WRKSRC=		${WRKDIR}/grub-${PORTVERSION}
SSP_UNSAFE=	yes
USE_GCC=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPE_PRODUCT=	grub
CPE_VENDOR=	gnu

CONFIGURE_ARGS=	--with-platform=efi --disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

.include <bsd.port.pre.mk>

post-patch:
	@${LN} -s ${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

pre-configure:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 ${WRKSRC}/grub-core

do-install:
	@cd ${WRKSRC}/grub-core && ${GMAKE} install DESTDIR=${STAGEDIR}

RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}

.include <bsd.port.post.mk>
