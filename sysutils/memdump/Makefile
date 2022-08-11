PORTNAME=	memdump
PORTVERSION=	1.01
CATEGORIES=	sysutils
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	onatan@gmail.com
COMMENT=	Forensic utility for memory dumping

LICENSE=	IBM
LICENSE_NAME=	IBM Public License 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ALL_TARGET=	what
MAKE_ARGS=	OPT="${CFLAGS}" DEBUG=''

PORTDOCS=	README
PLIST_FILES=	bin/memdump man/man1/memdump.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memdump.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
