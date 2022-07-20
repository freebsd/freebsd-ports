PORTNAME=	flip
PORTVERSION=	1.19
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/itetcu
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert text file line endings between Unix and DOS formats

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	bsd
PLIST_FILES=	bin/flip man/man1/flip.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flip.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
