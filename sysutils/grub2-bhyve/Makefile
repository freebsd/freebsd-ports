# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2-bhyve
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT= 	Grub-emu loader for bhyve

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		help2man:${PORTSDIR}/misc/help2man

ONLY_FOR_ARCHS=	amd64
SSP_UNSAFE=	yes
USE_GCC=	4.7
USE_GITHUB=	yes
GH_ACCOUNT=	grehan-freebsd
GH_COMMIT=	aa0717f
GH_TAGNAME=	v0.2
USES=		bison gettext gmake
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--with-platform=emu CC=gcc47 LEX=${LOCALBASE}/bin/flex \
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
