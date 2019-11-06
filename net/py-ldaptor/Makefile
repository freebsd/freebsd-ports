# Created by: bra@fsn.hu
# $FreeBSD$

PORTNAME=	ldaptor
PORTVERSION=	0.0.43
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://ftp.fsn.hu/contrib/bra/ldaptor/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ldaptor-${PORTVERSION}-${GITVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	Pure-python LDAP module for Twisted

BROKEN=		unfetchable

LICENSE=	MIT LGPL21+
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

GITVERSION=	aad8ded658b36337a08aeb7402b6b67eb8771bea

NO_ARCH=	yes
USES=		gettext python:2.7
USE_PYTHON=	distutils autoplist

PYDISTUTILS_INSTALL_TARGET=	install_locale install
PYDISTUTILS_BUILD_TARGET=	build_locale build

PLIST_FILES=	share/locale/fi/LC_MESSAGES/ldaptor-webui.mo \
		share/locale/fr/LC_MESSAGES/ldaptor-webui.mo

.include <bsd.port.mk>
