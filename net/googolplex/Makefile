# ex:ts=8
# Ports collection makefile for:	googolplex
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	googolplex
PORTVERSION=	0.1.0
CATEGORIES=	net python
MASTER_SITES=	http://googolplex.sourceforge.net/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query Google, parse it and returns the result as a list

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/googolplex.py
USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/googolplex.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
