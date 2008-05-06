# New ports collection makefile for:	pwman3
# Date created:				29 March 2008
# Whom:					Yarodin <yarodin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pwman3
PORTVERSION=	0.0.6
CATEGORIES=	security python
MASTER_SITES=	http://pwman.bleurgh.com/~ivan/pwman3/source/ \
		http://source.antisupport.com/pwman3/
DISTNAME=	Pwman3-${PORTVERSION}

MAINTAINER=	yarodin@gmail.com
COMMENT=	Console password management application with sql storage

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}cElementTree>=1.0.5:${PORTSDIR}/devel/py-celementtree \
		${PYTHON_PKGNAMEPREFIX}pysqlite>=2.0.5:${PORTSDIR}/databases/py-pysqlite23

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Pwman3

.include <bsd.port.mk>
