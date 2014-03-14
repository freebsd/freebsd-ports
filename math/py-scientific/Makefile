# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scientific
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/2309/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ScientificPython-${PORTVERSION}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Collection of Python modules for scientific computing

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	ScientificPython

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/Doc; ${TAR} -c --exclude='*~' -f - . | \
	    (cd ${DOCSDIR}; ${TAR} -xf -)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR}/${DISTNAME}/Examples; ${TAR} -c --exclude='*~' -f - . | \
	    (cd ${EXAMPLESDIR}; ${TAR} -xf -)
.endif

.include <bsd.port.mk>
