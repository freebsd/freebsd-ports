# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	svnmailer
DISTVERSION=	1.1.0-dev-r1373
PORTREVISION=	6
CATEGORIES=	mail python
MASTER_SITES=	http://storage.perlig.de/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to post subversion repository commit information

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>0:devel/py-subversion@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7 tar:bzip2
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "1s|^.*|#!${PYTHON_CMD}|" \
		-e 's,distutils\.command import install ,setuptools\.command import install ,' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/src/svn-mailer

.include <bsd.port.mk>
