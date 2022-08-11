PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.0.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quick search GUI tool for Unix-like systems

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	DoTheEvo
GH_PROJECT=	ANGRYsearch

USES=		python pyqt:5
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	pyqt5_run

post-patch:
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS}, ; s,linux,${OPSYS:tl}, \
		; s,/usr/share,${PREFIX}/share,' ${WRKSRC}/setup.py \
		${WRKSRC}/angrysearch.desktop

.include <bsd.port.mk>

PATCH_ARGS+=	-l
