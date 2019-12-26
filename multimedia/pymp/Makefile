# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pymp
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	multimedia python
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lean, flexible frontend to MPlayer written in Python

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mplayer:multimedia/mplayer

USE_GITHUB=	yes
GH_ACCOUNT=	jdolan
GH_TAGNAME=	bea99d9

USES=		gnome python:2.7 shebangfix
SHEBANG_FILES=	*.py
USE_GNOME=	pygtk2
NO_ARCH=	yes

PORTDOCS=	CHANGELOG README.md

DESKTOP_ENTRIES="Pymp" "" "${PORTNAME}" \
		"${PORTNAME}" "AudioVideo;Player;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|; \
		s|PREFIX/lib/pymp|${DATADIR}|' ${WRKSRC}/${PORTNAME}
	@${RM} ${WRKSRC}/build.py

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
