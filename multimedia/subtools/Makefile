# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subtools
PORTVERSION=	20081026
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tools for movie subtitles in SubRipper format

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		python tar:bzip2

PLIST_FILES=	bin/srtshift bin/srtrate bin/udvd2srt.py bin/udvdshift.py

PORTDOCS=	CHANGELOG.TXT README.TXT
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py

do-build:
.for f in srtshift srtrate
	cd ${WRKSRC} && ${CC} ${CFLAGS} -D${f:tu} -o ${f} ${PORTNAME}.c
.endfor

do-install:
.for f in srtshift srtrate
	@(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${f} ${STAGEDIR}${PREFIX}/bin/)
.endfor
.for f in *.py
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${f} ${STAGEDIR}${PREFIX}/bin/)
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
