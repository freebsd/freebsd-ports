# Created by: Søren Straarup <xride@x12.dk>
# $FreeBSD$

PORTNAME=	jonpy
PORTVERSION=	0.10
CATEGORIES=	www python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Python FastCGI interface library

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
NO_BUILD=		yes

PORTDOCS=	*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})

.include <bsd.port.mk>
