# Created by: Dmitriy Kirhlarov <dimma@higis.ru>
# $FreeBSD$

PORTNAME=	cyruslib
PORTVERSION=	0.5
CATEGORIES=	mail net python
MASTER_SITES=	http://oss.netfarm.it/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py
EXTRACT_SUFX=

MAINTAINER=	dimma@higis.ru
COMMENT=	Cyrus imapd library for Python

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		python
USE_PYTHON=	pythonprefix
BINMODE=	644

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${DISTNAME}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.mk>
