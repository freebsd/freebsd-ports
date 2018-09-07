# Created by: Yasuhiro KIMURA <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	lockfile-progs
PORTVERSION=	0.1.18
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Programs for locking and unlocking files and mailboxes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblockfile.so:devel/liblockfile

ALL_TARGET=	lockfile-create
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	TODO changelog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lockfile-create ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lockfile-progs.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for f in lockfile-remove lockfile-touch lockfile-check mail-lock mail-unlock mail-touchlock
	${LN} ${STAGEDIR}${PREFIX}/bin/lockfile-create ${STAGEDIR}${PREFIX}/bin/${f}
	${LN} -s lockfile-progs.1 ${STAGEDIR}${MANPREFIX}/man/man1/${f}.1
.endfor
	${LN} -s lockfile-progs.1 ${STAGEDIR}${MANPREFIX}/man/man1/lockfile-create.1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in TODO debian/changelog
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
