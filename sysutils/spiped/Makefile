# $FreeBSD$

PORTNAME=	spiped
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Daemon for creating secure symmetric pipes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# Ask to have man pages installed
MAKE_ARGS=	MAN1DIR=${MANPREFIX}/man/man1
MAN1=		spiped.1 spipe.1

# Binaries go into ${PREFIX}/bin
MAKE_ARGS+=	BINDIR=${PREFIX}/bin

# Force __BSD_VISIBLE on since it works and improves performance
MAKE_ARGS+=	CFLAGS="-O2 -D__BSD_VISIBLE"

PORTDOCS=	BUILDING CHANGELOG COPYRIGHT README STYLE
PLIST_FILES=	bin/spiped bin/spipe

USE_RC_SUBR=	spiped

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
