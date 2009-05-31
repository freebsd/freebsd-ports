# New ports collection makefile for: filetype
# Date created:        May 31 2009
# Whom:                ismail.yenigul@endersys.com.tr
#
# $FreeBSD$
#

PORTNAME=	filetype
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pldaniels.com/filetype/

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	New file-type detection system

MAN1=		filetype.1 filetype-compile.1
PORTDOCS=	README CHANGELOG CONTRIBUTORS INSTALL LICENSE TODO

PLIST_FILES=	bin/filetype

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filetype ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/filetype.1 ${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/filetype-compile.1 ${MANPREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
