# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libtheora
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Theora Video Compression Codec (Linux  CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libtheora-[0-9]* linux-f10-libtheora[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	2.el6
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtheora.so.0 usr/lib/libtheora.so.0.3.9 \
		usr/lib/libtheoradec.so.1 usr/lib/libtheoradec.so.1.1.3 \
		usr/lib/libtheoraenc.so.1 usr/lib/libtheoraenc.so.1.1.2
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
