# New ports collection makefile for:	linux-lesstif-ns
# Date created:		7 May 2000
# Whom:			imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	lesstif
PORTVERSION=	0.92.26
PORTREVISION=	3
CATEGORIES=	www x11-toolkits linux
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/obsolete/ \
		ftp://ftp.rge.com/pub/X/lesstif/srcdist/ \
		ftp://ftp.rge.com/pub/X/lesstif/srcdist/obsolete/ \
		ftp://ftp.kddlabs.co.jp/X11/lesstif/srcdist/ \
		ftp://ftp.kddlabs.co.jp/X11/lesstif/srcdist/obsolete/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-ns

PATCH_SITES=	http://cgi.shikoku.ne.jp/~fun/srpms/
PATCHFILES=	${DISTNAME}-i18n.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Clone of the Motif library mostly for linux-netscape4

DEPRECATED=		No port depends upon this port anymore.
EXPIRATION_DATE=	2005-08-20
IGNORE=			Does not build and nobody seems to complain.

# XXX: We should use a RPM instead of building it from source.
BUILD_DEPENDS=	${LINUXBASE}/usr/bin/cc:${PORTSDIR}/devel/linux_devtools

USE_BZIP2=	yes
USE_LINUX=	yes
PREFIX?=	${LINUXBASE}${X11BASE}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${MACHINE_ARCH}--linux-gnu \
		--enable-shared --enable-production \
		--enable-build-12 --enable-default-12 --disable-build-20 \
		--disable-debug --no-recursion \
		--without-motif --disable-build-Xlt --disable-build-Xbae
GMAKE=		${LINUXBASE}/usr/bin/make

pre-configure:
	@${ECHO_MSG} "*** Loading the Linux loadable kernel module (Error will be ignored) ***"
	-@linux

do-build:
	cd ${WRKSRC}/lib/Xm && ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Xm/.libs/libXm.so.1.0.2 \
					${PREFIX}/lib/libXm-ns.so.1.0.2
	${LN} -sf libXm-ns.so.1.0.2 ${PREFIX}/lib/libXm.so.1
	${LN} -sf libXm.so.1 ${PREFIX}/lib/libXm.so
	${LINUXBASE}/sbin/ldconfig

.include <bsd.port.mk>

CONFIGURE_ENV+=	${LINUXBASE}/bin/bash
