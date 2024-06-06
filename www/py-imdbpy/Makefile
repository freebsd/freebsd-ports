PORTNAME=	imdbpy
PORTVERSION=	2021.4.18
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		SF/${PORTNAME}/IMDbPY/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database
WWW=		http://imdbpy.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	IMDbPY is now cinemagoer. Use www/py-cinemagoer instead
EXPIRATION_DATE=2024-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLALCHEMY14
SQLALCHEMY14_DESC=	Use SQLAlchemy 1.4.x as backend

SQLALCHEMY14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR}

.include <bsd.port.mk>
