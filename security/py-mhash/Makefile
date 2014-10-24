# Created by: ijliao
# $FreeBSD$

PORTNAME=	mhash
PORTVERSION=	1.4
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-mhash-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python mhash module

LIB_DEPENDS=	libmhash.so:${PORTSDIR}/security/mhash

USES=		python
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

test: install
	${PYTHON_CMD} ${WRKSRC}/test.py

.include <bsd.port.mk>
