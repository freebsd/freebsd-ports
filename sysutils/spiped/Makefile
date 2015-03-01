# $FreeBSD$

PORTNAME=	spiped
PORTVERSION=	1.5.0
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.tarsnap.com/spiped/

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Daemon for creating secure symmetric pipes

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# The spiped build only needs C99, but this will help to get us a compiler
# which has support for AESNI on x86 systems
USES=		compiler:c11 tar:tgz

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

.include <bsd.port.options.mk>
.if ${OSVERSION} < 900503
EXTRA_PATCHES=	${FILESDIR}/extra-patch-proto_proto__conn.c
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
