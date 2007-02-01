# New ports collection makefile for:	fusefs-ntfs
# Date created: 			25 July 2006
# Whom:					Max Khon
# $FreeBSD$
#

PORTNAME=	ntfs
PORTVERSION=	0.20070118.BETA
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ntfs-3g.org/
MASTER_SITE_SUBDIR=	fuse
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g-${PORTVERSION:S,.BETA,-BETA,}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Mount NTFS partitions and disk images

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	fusefs-libs>=2.6.0:${PORTSDIR}/sysutils/fusefs-libs

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	yes
MAN8=		ntfs-3g.8

post-patch:
	@${CP} ${FILESDIR}/unix_io_raw.c ${WRKSRC}/libntfs-3g

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
