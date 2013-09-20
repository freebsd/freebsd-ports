# Created by: ijliao
# $FreeBSD$

PORTNAME=	imdbpy
PORTVERSION=	4.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/IMDbPY/${PORTVERSION:S/.2//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:${PORTSDIR}/databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}sqlobject>=0:${PORTSDIR}/databases/py-sqlobject

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	IMDbPY
PYEASYINSTALL_ARCHDEP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/bin/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
