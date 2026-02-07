PORTNAME=	offpunk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
CATEGORIES=	www python
MASTER_SITES=	https://git.sr.ht/~lioploum/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	m.ne@gmx.net
COMMENT=	Offline-first gemini/web/gopher/rss reader and browser
WWW=		https://sr.ht/~lioploum/offpunk/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readability-lxml>0:www/py-readability-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist cryptography pep517
SHEBANG_FILES=	ansicat.py netcache.py offpunk.py opnk.py

NO_ARCH=	yes

OPTIONS_DEFINE=	CHAFA CHARDET SETPROCTITLE TIMG XSEL

CHAFA_DESC=		Allows to display pictures in your console
CHARDET_DESC=		Detect the character encoding on Gopher
SETPROCTITLE_DESC=	Change the process name to "offpunk"
TIMG_DESC=		Slower alternative to chafa for inline images
XSEL_DESC=		Allows to go to the URL copied in the clipboard

CHAFA_RUN_DEPENDS=		chafa>=1.3.2>0:graphics/chafa
CHARDET_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}
SETPROCTITLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}
TIMG_RUN_DEPENDS=		timg>=1.3.2>0:graphics/timg
XSEL_RUN_DEPENDS=		xsel-conrad>0:x11/xsel-conrad

.include <bsd.port.mk>
