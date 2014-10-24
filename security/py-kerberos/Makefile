# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=		kerberos
PORTVERSION=		1.1.1
PORTREVISION=		1
CATEGORIES=		security python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		roland@micite.net
COMMENT=		Kerberos bindings for python

LICENSE=		APACHE20

BUILD_DEPENDS=		libkrb5-config.so:${PORTSDIR}/security/krb5
LIB_DEPENDS=		libkrb5support.so:${PORTSDIR}/security/krb5

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|krb5|${PREFIX}/bin/krb5|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|split|replace("/usr/lib:", "").split|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
