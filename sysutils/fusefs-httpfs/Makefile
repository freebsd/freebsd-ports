# New ports collection makefile for:	fusefs-httpfs
# Date created:		2006-07-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	httpfs
PORTVERSION=	2.06.07.10
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Fuse-based http filesystem

RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

PLIST_FILES=	bin/httpfs
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include/fuse \
	 -DUSE_AUTH -D_FILE_OFFSET_BITS=64 -D_REENTRANT \
	 -DFUSE_USE_VERSION=25 -D_POSIX_C_SOURCE=200112L -D_POSIX_SOURCE \
	 -D_SVID_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=500 \
	 -o httpfs httpfs.c -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lfuse)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httpfs ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from sysutils/fusefs-kmod
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
