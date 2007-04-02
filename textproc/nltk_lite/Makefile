# ex:ts=8
# Ports collection makefile for:	nltk_lite
# Date created:				Sat Nov 26 11:13:22 CST 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	nltk_lite
PORTVERSION=	0.7.2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:C/_.*//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Lightweight Natural language toolkit written in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python2.5"
PLIST_SUB+=	EGG_INFO_FILE=${PYTHON_SITELIBDIR:S;${PREFIX}/;;}/${PORTNAME}-${PORTVERSION}-py${_PYTHON_VERSION}.egg-info
.else
PLIST_SUB+=	EGG_INFO_FILE=""
.endif

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/nltk_lite ! -type d | \
		${SED} 's,^${TARGETDIR}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/nltk_lite -type d | ${SORT} -r | \
		${SED} 's,^${TARGETDIR}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
