PORTNAME=	html2text
DISTVERSION=	2024.2.26
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Convert HTML into clean plain ASCII text
WWW=		https://github.com/Alir3z4/html2text/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest
NO_ARCH=	yes

CONFLICTS_INSTALL=	html2text py*-html2text2018 # bin/html2text

.include <bsd.port.mk>
