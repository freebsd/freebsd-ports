# Created by: ijliao
# $FreeBSD$

PORTNAME=	pow
PORTVERSION=	0.7
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/POW/POW-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Python OpenSSL Wrappers

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	POW
USE_OPENSSL=	yes

PORTDOCS=	POW.pdf

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|licence|license|' ${WRKSRC}/setup.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext -D NO_IDEA ${PYDISTUTILS_BUILD_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
