# $FreeBSD$

PORTNAME=	spiped
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Daemon for creating secure symmetric pipes

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# Install into ${STAGEDIR}${PREFIX}
MAKE_ARGS+=	BINDIR=${STAGEDIR}${PREFIX}/bin
MAKE_ARGS+=	MAN1DIR=${STAGEDIR}${PREFIX}/man/man1

# Force __BSD_VISIBLE on since it works and improves performance
MAKE_ARGS+=	CFLAGS="-O2 -D__BSD_VISIBLE"

PORTDOCS=	BUILDING CHANGELOG COPYRIGHT README STYLE
PLIST_FILES=	bin/spipe \
		bin/spiped \
		man/man1/spipe.1.gz \
		man/man1/spiped.1.gz

USE_RC_SUBR=	spiped

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
