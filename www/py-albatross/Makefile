# Created by: Gregory Bond <gnb@itga.com.au>
# $FreeBSD$

PORTNAME=	albatross
PORTVERSION=	1.36
CATEGORIES=	www python
MASTER_SITES=	http://object-craft.com.au/projects/albatross/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-html-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnb@itga.com.au
COMMENT=	Python toolkit for developing highly stateful web applications

LICENSE=	BSD3CLAUSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}/html
	@${TAR} -cf - -C ${WRKSRC}/doc . | ${TAR} -xf - -C ${STAGEDIR}${DOCSDIR}
	@${TAR} -cf - -C ${WRKDIR}/albatross-html-${PORTVERSION} . | ${TAR} -xf - -C ${STAGEDIR}${DOCSDIR}/html
	@${TAR} -cf - -C ${WRKSRC}/samples . | ${TAR} -xf - -C ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
