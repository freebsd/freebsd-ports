# New ports collection makefile for:	py-qt4-doc
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	1
PORTEPOCH=	1

CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	${PYQT_MAINTAINER}
COMMENT=	Python bindings for the Qt4 toolkit, documentation

NO_BUILD=	yes
USE_PYTHON=	2.5+

DOCSDIR=	${PREFIX}/share/doc/py-qt4

do-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR} &&\
		${INSTALL_DATA} ChangeLog GPL_EXCEPTION.TXT\
				GPL_EXCEPTION_ADDENDUM.TXT LICENSE NEWS\
				OPENSOURCE-NOTICE.TXT README THANKS\
			${DOCSDIR} &&\
		${CP} -R doc/ ${DOCSDIR}
.else
	@${ECHO} "NOPORTDOCS is set -- installing nothing."
.endif

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.mk>
