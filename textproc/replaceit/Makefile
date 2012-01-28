# New ports collection makefile for:	replaceit
# Date created:				Fri Aug 17 20:15:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	replaceit
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://pldaniels.com/replaceit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A light replacement to the combination of sed/awk/grep/head/tail

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	CC="${CC}" PRF="${CFLAGS}"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/replaceit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replaceit ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
