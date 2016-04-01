# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clamav
PORTVERSION=	0.4.1
PORTREVISION=	6
CATEGORIES=	security python
MASTER_SITES=	http://xael.org/norman/python/pyclamav/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding to libclamav written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

BROKEN=		unfetchable
DEPRECATED=	Not updated since 2008 by upstream and abandoned in favor of pyClamd (security/py-pyclamd)
EXPIRATION_DATE=	2016-03-31

LIB_DEPENDS=	libclamav.so:security/clamav

DIST_SUBDIR=	python
USES=		python
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyclamav.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
