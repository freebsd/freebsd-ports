# New ports collection makefile for:	linux-lesstif-ns
# Date created:		7 May 2000
# Whom:			imura@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.91.0
CATEGORIES=	www x11-toolkits linux
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/  \
		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/lesstif/srcdist/ \
		ftp://ftp.win.or.jp/pub/X11/misc/lesstif/srcdist/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-ns

PATCH_SITES=	http://cgi.shikoku.ne.jp/~fun/srpms/
PATCHFILES=	${DISTNAME}-i18n.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	imura@FreeBSD.org

BUILD_DEPENDS=	${LINUX_BASE}/usr/bin/cc:${PORTSDIR}/devel/linux_devtools
RUN_DEPENDS=	${LINUX_BASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

LINUX_BASE=	/compat/linux
PREFIX=		${LINUX_BASE}${X11BASE}
NO_MTREE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${MACHINE_ARCH}--linux-gnu --enable-shared --enable-production \
		--disable-build-20 --disable-debug --no-recursion \
		--without-motif --disable-build-Xlt --disable-build-Xbae
GMAKE=		${LINUX_BASE}/usr/bin/make

do-build:
	cd ${WRKSRC}/lib/Xm && ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Xm/.libs/libXm.so.1.0.2 \
					${PREFIX}/lib/libXm-ns.so.1.0.2
	${LN} -sf libXm-ns.so.1.0.2 ${PREFIX}/lib/libXm.so.1
	${LN} -sf libXm.so.1 ${PREFIX}/lib/libXm.so
	${LINUX_BASE}/sbin/ldconfig

.include <bsd.port.mk>

CONFIGURE_ENV+=	${LINUX_BASE}/bin/bash
