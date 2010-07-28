# Ports collection makefile for:	nltk
# Date created:				Oct 30, 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	nltk
PORTVERSION=	2.0b8
PORTEPOCH=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Natural language toolkit written in python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	ASL
LICENSE_FILE_ASL=	${WRKSRC}/LICENSE.txt

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/nltk ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/nltk -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
