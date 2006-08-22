# New ports collection makefile for:	fusefs-sqlfs
# Date created:		2006-08-19
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	sqlfs
PORTVERSION=	20060811
CATEGORIES=	sysutils
MASTER_SITES=	http://www.palmsource.com/opensource/downloads/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	SQLite backed FUSE file system

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_SQLITE=	3
WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

PLIST_FILES=	bin/sqlfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

do-build:
	(cd ${WRKSRC} && ${CC} -DFUSE -DFUSE_USE_VERSION=25		\
		-D_FILE_OFFSET_BITS=64 -D_REENTRANT ${CFLAGS}		\
		-I${LOCALBASE}/include -I. -L${LOCALBASE}/lib		\
		-lfuse -lsqlite${SQLITE_VER} ${PTHREAD_CFLAGS}		\
		${PTHREAD_LIBS} sqlfs.c fuse_main.c -o sqlfs)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlfs ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
