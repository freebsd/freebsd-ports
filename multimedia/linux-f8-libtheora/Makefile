# New ports collection makefile for:	multimedia/linux-f8-libtheora
# Date created:				2008-10-15
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libtheora
PORTVERSION=	1.0beta2
PORTREVISION=	1
CATEGORIES=	multimedia linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Theora Video Compression Codec (Linux Fedora 8)

CONFLICTS=	linux-libtheora-[0-9]* linux-f10-libtheora-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	3.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtheora.so.0 usr/lib/libtheora.so.0.3.2
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
