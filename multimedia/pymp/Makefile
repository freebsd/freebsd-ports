# Created by:   nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	pymp
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	http://jdolan.dyndns.org/files/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lean, flexible frontend to MPlayer written in Python

LICENSE=	GPLv2

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2

PORTDOCS=	CHANGELOG README

DESKTOP_ENTRIES="Pymp" "MPlayer frontend" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "AudioVideo;Player;" "false"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
	-e 's|PREFIX/lib/pymp|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}
	${RM} -f ${WRKSRC}/build.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

	${MKDIR} ${DATADIR}
.for d in *.py *.pyc *.pyo
	${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}
.endfor

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
