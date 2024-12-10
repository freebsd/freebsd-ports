PORTNAME=	lockfile-progs
DISTVERSION=	0.1.20
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Programs for locking and unlocking files and mailboxes
WWW=		https://tracker.debian.org/pkg/lockfile-progs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblockfile.so:devel/liblockfile

USES=		tar:xz

ALL_TARGET=	lockfile-create
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

PORTDOCS=	changelog

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lockfile-create ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1
.for f in lockfile-remove lockfile-touch lockfile-check mail-lock mail-unlock \
	mail-touchlock
	${LN} ${STAGEDIR}${PREFIX}/bin/lockfile-create ${STAGEDIR}${PREFIX}/bin/${f}
	${LN} -s lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1/${f}.1
.endfor
	${LN} -s lockfile-progs.1 ${STAGEDIR}${PREFIX}/share/man/man1/lockfile-create.1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
