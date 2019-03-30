# $FreeBSD$

PORTNAME=	zol
PORTVERSION=	2019033000
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	ZFS on Linux userland for FreeBSD

LICENSE=	CDDL

BROKEN_aarch64=	invokes x86 assembler

RUN_DEPENDS=	zol-kmod>=0:sysutils/zol-kmod

USES=		autoreconf:build libtool gmake gettext-runtime:run

GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-config="user"

OPTIONS_DEFINE= DEBUG
OPTIONS_SUB=    yes

USE_GITHUB=	yes
GH_ACCOUNT=	zfsonfreebsd
GH_PROJECT=	ZoF
GH_TAGNAME=	a6d2a2d

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1200504) || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300013)
IGNORE=      needs FreeBSD 12/13 with AES-CCM support
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-debuginfo
.endif

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.post.mk>
