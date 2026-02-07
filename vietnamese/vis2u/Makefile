PORTNAME=	vis2u
PORTVERSION=	1.0
CATEGORIES=	vietnamese textproc
MASTER_SITES=	LOCAL/obrien
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VISCII->Unicode conversion

USES=		zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/vis2u

do-build:
	${CC} -x c ${CFLAGS} ${WRKSRC}/VIS2U.C -o ${WRKSRC}/vis2u

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vis2u ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
