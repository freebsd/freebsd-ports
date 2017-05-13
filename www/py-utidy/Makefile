# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utidy
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/utidylib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uTidylib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to tidy-lib

# XXX Better depend on tidy or tidy-devel???
LIB_DEPENDS=	libtidy.so:www/tidy-lib

USES=		python:2 zip
USE_PYTHON=	distutils autoplist

BROKEN=		checksum mismatch

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
