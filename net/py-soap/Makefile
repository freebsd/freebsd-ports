# New ports collection makefile for:	py-soap
# Date created:		24 May 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	soap
PORTVERSION=	0.8
CATEGORIES=	net python
MASTER_SITES=	http://www.pythonware.com/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}lib-${PORTVERSION}-${PORTRELDATE}

MAINTAINER=	perky@FreeBSD.org

PORTRELDATE=	20000621
USE_PYTHON=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qa
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g} \
		SHARE_SUBDIR=${SHARE_SUBDIR}
SHARE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

DOC_FILES=	ANNOUNCE README
LIB_FILES=	soaplib.py soaplib.pyc soapserver.py
EXAMPLE_FILES=	test1.py test2.py test3.py

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/${SHARE_SUBDIR}
	${MKDIR} ${PREFIX}/share/examples/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLE_FILES} ${PREFIX}/share/examples/${SHARE_SUBDIR}
.endif
	${MKDIR} ${PYTHON_SITELIBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${LIB_FILES} ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
