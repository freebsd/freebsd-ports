# $FreeBSD$

PORTNAME=	terminfo
PORTVERSION=	20201128
DISTVERSIONSUFFIX=	.src
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.invisible-island.net/ncurses/current/ \
		https://invisible-mirror.net/archives/ncurses/current/
PKGNAMESUFFIX=	-db
EXTRACT_SUFX=	.gz

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Terminal Description database

LICENSE=	MIT

BUILD_DEPENDS=	tic:devel/ncurses

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}.src

NO_WRKSUBDIR=	yes

do-build:
	${MKDIR} ${WRKSRC}/${PORTNAME}
	tic -sx -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.src

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/${PORTNAME}; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
