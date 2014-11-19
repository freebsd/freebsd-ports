# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	pyang
PORTVERSION=	1.4.1
CATEGORIES=	net-mgmt python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Validator and code generator for YANG (RFC 4741)

LICENSE=	BSD

USES=		python
USE_PYTHON=	distutils

DATADIR=	${PREFIX}/share/yang

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
