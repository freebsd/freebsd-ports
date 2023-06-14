PORTNAME=	ibus-uniemoji
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0-16
DISTVERSIONSUFFIX=	-ga26c364
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Input method for entering unicode symbols and emoji by name
WWW=		https://github.com/salty-horseibus-uniemoji

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-Levenshtein>0:devel/py-python-Levenshtein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:textproc/ibus

USES=		gmake gnome python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	salty-horse
USE_GNOME=	glib20 pygobject3
SHEBANG_GLOB=	*.py

MAKE_ENV=	PYTHON=${PYTHON_CMD} SYSCONFDIR=${PREFIX}/etc

.include <bsd.port.mk>
