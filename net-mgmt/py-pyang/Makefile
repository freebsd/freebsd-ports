# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	pyang
PORTVERSION=	1.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validator and code generator for YANG (RFC 4741)

LICENSE=	BSD

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

DATADIR=	${PREFIX}/share/yang

MAN1=		pyang.1 yang2dsdl.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
