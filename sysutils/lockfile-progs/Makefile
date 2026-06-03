PORTNAME=	lockfile-progs
DISTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs for locking and unlocking files and mailboxes
WWW=		https://tracker.debian.org/pkg/lockfile-progs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed
LIB_DEPENDS=	liblockfile.so:devel/liblockfile

USES=		gmake localbase:ldflags tar:xz

MAKEFILE=	GNUmakefile
ALL_TARGET=	bin/lockfile-create man/lockfile-progs.1

BINARY_ALIAS=	sed=gsed

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

PORTDOCS=	changelog

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lockfile-create ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1
.for f in lockfile-check lockfile-remove lockfile-touch mail-lock mail-touchlock \
	mail-unlock
	${LN} ${STAGEDIR}${PREFIX}/bin/lockfile-create ${STAGEDIR}${PREFIX}/bin/${f}
	${LN} -s lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1/${f}.1
.endfor
	${LN} -s lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1/lockfile-create.1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
