# Created by: Milan Obuch
# $FreeBSD$

PORTNAME=	pyclamd
PORTVERSION=	0.2.2
CATEGORIES=	security python
MASTER_SITES=	http://xael.org/norman/python/pyclamd/
DISTFILES=	pyclamd.py

MAINTAINER=	bsd@dino.sk
COMMENT=	Python ClamD interface module

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKDIR}/${PKGNAME}
	if ! (cd ${WRKDIR} && ${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PKGNAME}/); \
	then \
		exit 1; \
	fi; \

.include <bsd.port.post.mk>
