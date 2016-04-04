# Created by: bra@fsn.hu
# $FreeBSD$

PORTNAME=	ldaptor
PORTVERSION=	0.0.43
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://ftp.fsn.hu/contrib/bra/ldaptor/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ldaptor-${PORTVERSION}-${GITVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	Pure-python LDAP module for Twisted

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl

GITVERSION=	aad8ded658b36337a08aeb7402b6b67eb8771bea

USES=		gettext python twisted
USE_PYTHON=	distutils autoplist
PYDISTUTILS_INSTALL_TARGET=	install_locale install
PYDISTUTILS_BUILD_TARGET=	build_locale build

.include <bsd.port.mk>
