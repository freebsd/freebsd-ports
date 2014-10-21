# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pymp
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	multimedia python
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lean, flexible frontend to MPlayer written in Python

LICENSE=	GPLv2

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_GITHUB=	yes
GH_ACCOUNT=	jdolan
GH_PROJECT=	pymp
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	bea99d9

USES=		shebangfix python tar:bzip2
SHEBANG_FILES=	*.py
python_OLD_CMD?=	/usr/bin/env python
python_CMD?=	${PYTHON_CMD}
USE_GNOME=	pygtk2

PORTDOCS=	CHANGELOG README.md
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Pymp" "" "${PORTNAME}" \
		"${PORTNAME}" "AudioVideo;Player;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|; \
		s|PREFIX/lib/pymp|${DATADIR}|' ${WRKSRC}/${PORTNAME}
	@${RM} -f ${WRKSRC}/build.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in *.py *.pyc *.pyo
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
