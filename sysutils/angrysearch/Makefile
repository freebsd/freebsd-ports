# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	angrysearch
PORTVERSION=	1.0.2 # untagged, but specified in the setup.py
PORTREVISION=	4
CATEGORIES=	sysutils python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quick search GUI tool for Unix-like systems

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	DoTheEvo
GH_PROJECT=	ANGRYsearch
GH_TAGNAME=	6f8fccc

USES=		python pyqt:5
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	core_run gui_run widgets_run

post-patch:
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS}, ; s,linux,${OPSYS:tl}, \
		; s,/usr/share,${PREFIX}/share,' ${WRKSRC}/setup.py \
		${WRKSRC}/angrysearch.desktop

.include <bsd.port.mk>

PATCH_ARGS+=	-l
