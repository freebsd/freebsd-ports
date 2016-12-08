# Created by: Max Khon
# $FreeBSD$

PORTNAME=	pod
PORTVERSION=	0.5.2
PORTREVISION=	13
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/fuse${PORTNAME}/fuse${PORTNAME}/FUSEPod%20v${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod

LIB_DEPENDS=	libgpod.so:audio/libgpod\
		libtag.so:audio/taglib

USES=		fuse pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/fusepod man/man1/fusepod.1.gz

.include <bsd.port.mk>
