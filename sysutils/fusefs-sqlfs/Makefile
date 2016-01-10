# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	sqlfs
PORTVERSION=	1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH/libsqlfs
PKGNAMEPREFIX=	fusefs-
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SQLite backed FUSE file system

USES=		fuse sqlite

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README

PLIST_FILES=	bin/sqlfs

do-build:
	(cd ${WRKSRC} && ${CC} -DFUSE -DFUSE_USE_VERSION=25		\
		-D_FILE_OFFSET_BITS=64 -D_REENTRANT ${CFLAGS}		\
		-I${LOCALBASE}/include -I. -L${LOCALBASE}/lib		\
		-lfuse -lsqlite${SQLITE_VER} sqlfs.c fuse_main.c 	\
		-o sqlfs)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlfs ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
