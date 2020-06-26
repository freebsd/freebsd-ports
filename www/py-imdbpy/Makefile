# Created by: ijliao
# $FreeBSD$

PORTNAME=	imdbpy
PORTVERSION=	6.8
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		SF/${PORTNAME}/IMDbPY/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	docs/goodies/download_applydiffs.py \
		docs/goodies/reduce.sh

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	SQLALCHEMY
OPTIONS_RADIO_SQLALCHEMY=	SQLALCHEMY11 SQLALCHEMY12 SQLALCHEMY13
SQLALCHEMY11_DESC=	Use SQLAlchemy 1.1.x as backend
SQLALCHEMY12_DESC=	Use SQLAlchemy 1.2.x as backend
SQLALCHEMY13_DESC=	Use SQLAlchemy 1.3.x as backend

SQLALCHEMY11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy11>=0:databases/py-sqlalchemy11@${PY_FLAVOR}
SQLALCHEMY12_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0:databases/py-sqlalchemy12@${PY_FLAVOR}
SQLALCHEMY13_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=0:databases/py-sqlalchemy13@${PY_FLAVOR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
