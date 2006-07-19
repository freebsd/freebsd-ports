# New ports collection makefile for:	fusefs-funionfs
# Date created:		2006-07-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	funionfs
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://funionfs.apiou.org/file/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	gslin@gslin.org
COMMENT=	Union filesystem for the FUSE driver

RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

PLIST_FILES=	bin/funionfs

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DFUSE_USE_VERSION=25 \
	 -D_FILE_OFFSET_BITS=64 -I${LOCALBASE}/include/fuse \
	 -o funionfs main.c \
	 -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lfuse)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funionfs ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from fusefs-kmod
IGNORE=		requires FreeBSD 6.x or above
.endif

.include <bsd.port.post.mk>
