PORTNAME=	bottle-cork
PORTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Bottle authentication and authorization module

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beaker>0:www/py-beaker@${PY_FLAVOR}

USES=		python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	FedericoCeratto

USE_PYTHON=	distutils autoplist
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		SQLITE MONGODB SQLALCHEMY EXAMPLES
MONGODB_DESC=		Add MongoDB support
SQLALCHEMY_DESC=	Add SQLAlchemy support
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/pymongo@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
