# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2-bhyve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Grub-emu loader for bhyve

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		help2man:misc/help2man

ONLY_FOR_ARCHS=	amd64
SSP_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	grehan-freebsd
USES=		bison gmake
USE_GCC=	yes
PLIST_FILES=	sbin/grub-bhyve
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--with-platform=emu CC=${CC} LEX=${LOCALBASE}/bin/flex \
		--enable-grub-mount=no --enable-grub-mkfont=no \
		--enable-grub-emu-sdl=no --disable-nls --disable-werror

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
IGNORE=	for FreeBSD 10 and higher
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/libintl\.h/I_do_not_want_libintl.h/g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/-lintl//g" ${WRKSRC}/grub-core/Makefile.in

do-configure:
	@ cd ${WRKSRC}/ && ./configure ${CONFIGURE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grub-core/grub-emu ${STAGEDIR}${LOCALBASE}/sbin/grub-bhyve

.include <bsd.port.post.mk>

RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
