PORTNAME=	finfo
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finfo displays potentially useful information about a file

PLIST_FILES=	bin/finfo man/man1/finfo.1.gz

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
