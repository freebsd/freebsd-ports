# Created by: Max Khon
# $FreeBSD$

PORTNAME=	pod
PORTVERSION=	0.5.2
PORTREVISION=	10
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/fuse${PORTNAME}/fuse${PORTNAME}/FUSEPod%20v${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod

LIB_DEPENDS=	gpod.7:${PORTSDIR}/audio/libgpod\
		tag.1:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USES=		fuse pkgconfig
GNU_CONFIGURE=	yes
MAN1=		fusepod.1
PLIST_FILES=	bin/fusepod

.include <bsd.port.mk>
