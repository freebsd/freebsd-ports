# New ports collection makefile for:	arcconf
# Date created:				28 October 2007
# Whom:					michael@fuckner.net
#
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	v5_30_17509
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	cli_freebsd${DIST_EXT}_${DISTVERSION}

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI RAID administration tool

ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	yes

PLIST_FILES=	sbin/arcconf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.endif

.if ${OSVERSION} >= 600000
.if ${ARCH} == amd64
DIST_EXT=	6_x64
.else
DIST_EXT=	6_x86
.endif
.endif

.if ${OSVERSION} < 600000
.if ${ARCH} == "i386"
DIST_EXT=	5_x86
.else
IGNORE=		combination OS/ARCH not supported
.endif
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arcconf ${PREFIX}/sbin

.include <bsd.port.post.mk>
