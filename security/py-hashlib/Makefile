# New ports collection makefile for:	py-hashlib
# Date created:				12 Dec 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	hashlib
PORTVERSION=	20081119
CATEGORIES=	security devel python
MASTER_SITES=	http://code.krypto.org/python/hashlib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Backport of Python 2.5's haslib module

USE_PYTHON=	-2.4
USE_OPENSSL=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
IGNORE=	hashlib ships with Python 2.5.x
.endif

.if ${OSVERSION} >= 700019
PLIST_SUB+=	OSSL="@comment "
.else
PLIST_SUB+=	OSSL=""
.endif

PYDISTUTIL_BUILDARGS=	--openssl-prefix=${OPENSSLDIR} --openssl-incdir=${OPENSSLINC} --openssl-libdir=${OPENSSLLIB}

.include <bsd.port.post.mk>
