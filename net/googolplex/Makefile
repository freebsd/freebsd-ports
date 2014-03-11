# Created by: ijliao
# $FreeBSD$

PORTNAME=	googolplex
PORTVERSION=	0.1.0
CATEGORIES=	net python
MASTER_SITES=	http://googolplex.sourceforge.net/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query Google, parse it and returns the result as a list

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/googolplex.py
USE_PYTHON=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/googolplex.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
