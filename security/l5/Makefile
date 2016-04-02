# Created by: andrew@scoop.co.nz
# $FreeBSD$

PORTNAME=	l5
PORTVERSION=	1.2
CATEGORIES=	security sysutils
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/l5/
DISTNAME=	L5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File Integrity Assessment Tool

USES=		tar:tgz

NO_WRKSUBDIR=	yes
ALL_TARGET=	freebsd

PLIST_FILES=	bin/l5
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

BROKEN_amd64=	incorrect runtime output

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
