# New ports collection makefile for:	py-ldaptor
# Date created:		10.Jun 2011
# Whom:			bra@fsn.hu
#
# $FreeBSD$

PORTNAME=	ldaptor
PORTVERSION=	0.0.43
CATEGORIES=	net python
MASTER_SITES=	http://ftp.fsn.hu/contrib/bra/ldaptor/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ldaptor-${PORTVERSION}-${GITVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	A pure-python LDAP module for Twisted

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl

GITVERSION=	aad8ded658b36337a08aeb7402b6b67eb8771bea

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_TWISTED=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.0.0
PYDISTUTILS_PKGNAME=	ldaptor

.include <bsd.port.mk>
