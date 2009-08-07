# New ports collection makefile for:	fusefs-pod
# Date created: 			22 Aug 2007
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	pod
PORTVERSION=	0.5.2
PORTREVISION=	5
CATEGORIES=	sysutils audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	fusepod/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs\
		gpod.5:${PORTSDIR}/audio/libgpod\
		tag.6:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		fusepod.1
PLIST_FILES=	bin/fusepod

.include <bsd.port.mk>
