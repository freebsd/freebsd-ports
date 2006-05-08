# New ports collection makefile for:	subtools
# Date created:		10 January 2005
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subtools
PORTVERSION=	20051215
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}alpha

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Command-line tools for movie subtitles in SubRipper format

PLIST_FILES=	bin/laudio
PORTDOCS=	readme.txt

WRKSRC=		${WRKDIR}/${PORTNAME}/src
EXECS=		srtshift srtrate

PORTDOCS=	CHANGELOG.TXT LICENSE.TXT README.TXT TODO.TXT
PLIST_FILES=	${EXECS:S/^/bin\//}

do-build:
.for EXEC in ${EXECS}
	cd ${WRKSRC} && ${CC} ${CFLAGS} -D${EXEC:U} -o ${EXEC} ${PORTNAME}.c
.endfor

do-install:
	${INSTALL_PROGRAM} ${EXECS:S/^/${WRKSRC}\//} ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S/^/${WRKSRC}\//} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
