# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scientific
PORTVERSION=	2.8
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/2309/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ScientificPython-${PORTVERSION}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Collection of Python modules for scientific computing

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/Doc; ${TAR} -c --exclude='*~' -f - . | \
	    (cd ${STAGEDIR}${DOCSDIR}; ${TAR} -xf -)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKDIR}/${DISTNAME}/Examples; ${TAR} -c --exclude='*~' -f - . | \
	    (cd ${STAGEDIR}${EXAMPLESDIR}; ${TAR} -xf -)

.include <bsd.port.mk>
