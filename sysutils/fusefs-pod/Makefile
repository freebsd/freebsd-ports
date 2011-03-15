# New ports collection makefile for:	fusefs-pod
# Date created: 			22 Aug 2007
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	pod
PORTVERSION=	0.5.2
PORTREVISION=	9
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/fuse${PORTNAME}/fuse${PORTNAME}/FUSEPod%20v${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs\
		gpod.7:${PORTSDIR}/audio/libgpod\
		tag.1:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		fusepod.1
PLIST_FILES=	bin/fusepod

.include <bsd.port.mk>
