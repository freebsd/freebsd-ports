# New ports collection makefile for:	linux-fontconfig
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.2.3
PORTREVISION=	4
CATEGORIES=	x11-fonts linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-5

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux/i386 binary of Fontconfig

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes

BRANDELF_DIRS=	usr/bin

post-extract:
	${RM} ${WRKSRC}/etc/fonts/fonts.conf

post-install:
	${LN} -s ${X11BASE}/etc/fonts/fonts.conf ${PREFIX}/etc/fonts/fonts.conf

.include <bsd.port.mk>
