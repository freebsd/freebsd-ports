# New ports collection makefile for:	py-qt4-doc
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	4.3
PORTREVISION=	# zero
CATEGORIES=	misc devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/PyQt4/GPL/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, documentation

NO_BUILD=	yes
USE_PYTHON=	2.5+

DOCSDIR=	${PREFIX}/share/doc/py-qt4

do-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR} &&\
		${INSTALL_DATA} ChangeLog NEWS README THANKS ${DOCSDIR} &&\
		${CP} -R doc/ ${DOCSDIR}
.else
	@${ECHO} "NOPORTDOCS is set -- installing nothing."
.endif

.include <bsd.port.mk>
