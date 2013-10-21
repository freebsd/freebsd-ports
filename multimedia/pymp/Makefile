# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pymp
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lean, flexible frontend to MPlayer written in Python

LICENSE=	GPLv2

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USES=		shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_PYTHON=	yes
USE_GNOME=	pygtk2

PORTDOCS=	CHANGELOG README

DESKTOP_ENTRIES="Pymp" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "AudioVideo;Player;" false

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX/lib/pymp|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}
	${RM} -f ${WRKSRC}/build.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in *.py *.pyc *.pyo
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
