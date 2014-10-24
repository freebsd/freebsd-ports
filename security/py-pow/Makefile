# Created by: ijliao
# $FreeBSD$

PORTNAME=	pow
PORTVERSION=	0.7
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/POW/POW-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Python OpenSSL Wrappers

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	POW
USE_OPENSSL=	yes

PORTDOCS=	POW.pdf

post-patch:
	${REINPLACE_CMD} -e 's|licence|license|' ${WRKSRC}/setup.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext -D NO_IDEA -D NO_RC5_32_12_16 ${PYDISTUTILS_BUILD_TARGET}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
