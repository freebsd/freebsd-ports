# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	mtrxmath
PORTVERSION=	1.0.2
CATEGORIES=	math
MASTER_SITES=	http://www.angelfire.com/linux/linuxjeff/mtrxmath/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small tool for matrix mathematics

LICENSE=	GPLv2

PORTDOCS=	README
PLIST_FILES=	bin/mtrxmath

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrxmath ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
