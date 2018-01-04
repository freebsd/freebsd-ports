# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	matrix-synapse-ldap3
PORTVERSION=	0.1.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	LDAP3 auth provider for Matrix Synapse

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap3>=0.9.5:net/py-ldap3@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
