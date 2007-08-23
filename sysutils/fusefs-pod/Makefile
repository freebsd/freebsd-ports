# New ports collection makefile for:	fusefs-pod
# Date created: 			22 Aug 2007
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	pod
PORTVERSION=	0.5.2
CATEGORIES=	sysutils audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	fusepod/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs\
		gpod.2:${PORTSDIR}/audio/libgpod\
		tag.5:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
MAN1=		fusepod.1
PLIST_FILES=	bin/fusepod

.include <bsd.port.mk>
