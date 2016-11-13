# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pydicom
PORTVERSION=	0.9.9
DISTVERSIONPREFIX=v
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read, modify, and write DICOM files with Python code

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/source

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	darcymason
SHEBANG_FILES=	dicom/test/shell_all
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
