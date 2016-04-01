# $FreeBSD$

PORTNAME=	bottle-cork
PORTVERSION=	0.12.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Bottle authentication and authorization module

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle \
		${PYTHON_PKGNAMEPREFIX}beaker>0:www/py-beaker

USE_GITHUB=	yes
GH_ACCOUNT=	FedericoCeratto

USES=		python
USE_PYTHON=	distutils autoplist
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		SQLITE MONGODB SQLALCHEMY EXAMPLES

.include <bsd.port.options.mk>

SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/pymongo
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:databases/py-sqlalchemy

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
