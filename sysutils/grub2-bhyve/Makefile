# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2-bhyve
DISTVERSION=	0.22
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Grub-emu loader for bhyve

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		help2man:${PORTSDIR}/misc/help2man

ONLY_FOR_ARCHS=	amd64
SSP_UNSAFE=	yes
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	grehan-freebsd
GH_COMMIT=	10795f1
GH_TAGNAME=	v0.22
USES=		bison gettext gmake
PLIST_FILES=	sbin/grub-bhyve
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--with-platform=emu CC=${CC} LEX=${LOCALBASE}/bin/flex \
		--enable-grub-mount=no --enable-grub-mkfont=no

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
IGNORE=	for FreeBSD 10 and higher
.endif

do-configure:
	@ cd ${WRKSRC}/ && ./configure ${CONFIGURE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grub-core/grub-emu ${STAGEDIR}${LOCALBASE}/sbin/grub-bhyve

.include <bsd.port.post.mk>
