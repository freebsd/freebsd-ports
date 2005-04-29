# ex:ts=8
# Ports collection makefile for:	py-mechanize
# Date created:			Apr 29, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mechanize
PORTVERSION=	0.0.9.a
CATEGORIES=	www python
MASTER_SITES=	http://wwwsearch.sourceforge.net/mechanize/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stateful programmatic web browsing in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ClientCookie/__init__.py:${PORTSDIR}/devel/py-clientcookie \
		${PYTHON_SITELIBDIR}/ClientForm.py:${PORTSDIR}/www/py-clientform \
		${PYTHON_SITELIBDIR}/pullparser.py:${PORTSDIR}/www/py-pullparser
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/mechanize ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/mechanize -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
