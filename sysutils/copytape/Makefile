# Created by: Stephen J. Roznowski <sjr@home.net>
# $FreeBSD$

PORTNAME=		copytape
PORTVERSION=		1.0
CATEGORIES=		sysutils
MASTER_SITES=		COMP_SOURCES/unix/volume10
DISTNAME=		copytape
EXTRACT_SUFX=		.Z

MAINTAINER=		sjroz@verizon.net
COMMENT=		Program that is used to duplicate magtapes

EXTRACT_DEPENDS=	gunshar:archivers/sharutils

NO_WRKSUBDIR=		yes

EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| gunshar -d ${WRKSRC}

CFLAGS+=	-Wno-return-type
# XXX upstream puts CFLAGS in CC
MAKE_ARGS+=	CC="${CC} ${CFLAGS}"
ALL_TARGET=	copytape

PLIST_FILES=	bin/copytape \
		man/man1/copytape.1.gz \
		man/man5/copytape.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copytape ${STAGEDIR}${PREFIX}/bin/copytape
	${INSTALL_MAN} ${WRKSRC}/copytape.1 ${STAGEDIR}${PREFIX}/man/man1/copytape.1
	${INSTALL_MAN} ${WRKSRC}/copytape.5 ${STAGEDIR}${PREFIX}/man/man5/copytape.5

.include <bsd.port.mk>
