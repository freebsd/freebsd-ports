# New ports collection makefile for:	py-pysendfile
# Date created:		2012-06-15
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pysendfile
PORTVERSION=	2.0.0
CATEGORIES=	net python devel
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	A Python interface to sendfile(2)

CONFLICTS_INSTALL=	py*-sendfile-[0-9]*

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
