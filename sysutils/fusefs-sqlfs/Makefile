# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	sqlfs
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	libsqlfs
PKGNAMEPREFIX=	fusefs-
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SQLite backed FUSE file system

USES=		fuse
USE_SQLITE=	3

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

PLIST_FILES=	bin/sqlfs

.include <bsd.port.pre.mk>

do-build:
	(cd ${WRKSRC} && ${CC} -DFUSE -DFUSE_USE_VERSION=25		\
		-D_FILE_OFFSET_BITS=64 -D_REENTRANT ${CFLAGS}		\
		-I${LOCALBASE}/include -I. -L${LOCALBASE}/lib		\
		-lfuse -lsqlite${SQLITE_VER} sqlfs.c fuse_main.c 	\
		-o sqlfs)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlfs ${STAGEDIR}${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
