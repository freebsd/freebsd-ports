PORTNAME=	pstree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.40
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/FredHucht/${PORTNAME}/files/9119465/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	List processes as a tree
WWW=		https://github.com/FredHucht/pstree

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	zip

CONFLICTS=	psmisc

PLIST_FILES=	bin/pstree share/man/man1/pstree.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstree.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
