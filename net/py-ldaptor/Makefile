# Created by: bra@fsn.hu
# $FreeBSD$

PORTNAME=	ldaptor
PORTVERSION=	0.0.43
CATEGORIES=	net python
MASTER_SITES=	http://ftp.fsn.hu/contrib/bra/ldaptor/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ldaptor-${PORTVERSION}-${GITVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	Pure-python LDAP module for Twisted

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl

GITVERSION=	aad8ded658b36337a08aeb7402b6b67eb8771bea

USES=		gettext twisted
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_INSTALL_TARGET=	install_locale install
PYDISTUTILS_BUILD_TARGET=	build_locale build

.include <bsd.port.mk>
