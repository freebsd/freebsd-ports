# New ports collection makefile for:	subtools
# Date created:		10 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subtools
PORTVERSION=	20060508
DISTVERSIONSUFFIX=	alpha
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tools for movie subtitles in SubRipper format

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
EXECS=		srtshift srtrate
PYEXECS=	udvd2srt.py udvdshift.py
PORTDOCS=	CHANGELOG.TXT LICENSE.TXT README.TXT TODO.TXT
PLIST_FILES=	${EXECS:S/^/bin\//} ${PYEXECS:S/^/bin\//}

post-patch:
	@${REINPLACE_CMD} -e 's,,,g;s,^.*#!.*python.*$$,#!${PYTHON_CMD},' ${WRKSRC}/*

do-build:
.for EXEC in ${EXECS}
	cd ${WRKSRC} && ${CC} ${CFLAGS} -D${EXEC:U} -o ${EXEC} ${PORTNAME}.c
.endfor

do-install:
	${INSTALL_PROGRAM} ${EXECS:S/^/${WRKSRC}\//} ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${PYEXECS:S/^/${WRKSRC}\//} ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S/^/${WRKSRC}\//} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
