# New ports collection makefile for:	py-qt4-doc
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	20070225 # Older snapshot, has complete docs
CATEGORIES=	misc devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/PyQt4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-4-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, documentation

NO_BUILD=	yes
USE_PYTHON=	yes

DOCSDIR=	${PREFIX}/share/doc/py-qt4

.include <bsd.port.pre.mk>

do-install:
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${DOCSDIR} && \
		${INSTALL_DATA} ChangeLog NEWS README THANKS ${DOCSDIR} && \
		${CP} -R doc/ ${DOCSDIR} )

.include <bsd.port.post.mk>
