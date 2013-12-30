# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=		kerberos
PORTVERSION=		1.1.1
CATEGORIES=		security python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		roland@micite.net
COMMENT=		Kerberos bindings for python

LICENSE=		APACHE20

BUILD_DEPENDS=		krb5-config:${PORTSDIR}/security/krb5
LIB_DEPENDS=		krb5support.0:${PORTSDIR}/security/krb5

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|krb5|${PREFIX}/bin/krb5|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|split|replace("/usr/lib:", "").split|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|distutils.core|setuptools|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
