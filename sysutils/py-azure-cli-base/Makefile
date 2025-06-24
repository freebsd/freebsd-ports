PORTNAME=	azure-cli-base
PORTVERSION=	1.0.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Shared namespace for py-azure-* ports

LICENSE=	MIT

NO_BUILD=	yes
NO_ARCH=	yes
USES=		python
USE_PYTHON=	flavors

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/command_modules
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/datalake
	${INSTALL_DATA}	${FILESDIR}/__init__.py	${STAGEDIR}${PYTHON_SITELIBDIR}/azure
	${INSTALL_DATA}	${FILESDIR}/__init__.py	${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli
	${INSTALL_DATA}	${FILESDIR}/__init__.py	${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/command_modules
	${INSTALL_DATA}	${FILESDIR}/__init__.py	${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt
	${INSTALL_DATA}	${FILESDIR}/__init__.py	${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/datalake
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
