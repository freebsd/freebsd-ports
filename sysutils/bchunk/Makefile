PORTNAME=	bchunk
DISTVERSION=	1.2.2
PORTREVIDSION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts .bin/.cue files to .iso/audio
WWW=		http://he.fi/bchunk/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
CPE_VENDOR=	bchunk_project

PLIST_FILES=	bin/bchunk share/man/man1/bchunk.1.gz

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} bchunk.c -o bchunk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
