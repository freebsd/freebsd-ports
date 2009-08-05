# New ports collection makefile for:	lshell
# Date created:		2009-08-01
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	lshell
PORTVERSION=	0.9.5
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Shell environment to limited sets of commands to user's

RUN_DEPENDS=	python:${PORTSDIR}/lang/python
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/lshell.py \
		%%PYTHON_SITELIBDIR%%/lshell.pyc \
		%%PYTHON_SITELIBDIR%%/lshell.pyo \
		bin/lshell \
		etc/lshell.conf

MAN1=	lshell.1

DOCS=	README COPYING CHANGES

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
