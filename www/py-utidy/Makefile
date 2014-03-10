# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utidy
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	utidylib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uTidylib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to tidy-lib

# XXX Better depend on tidy or tidy-devel???
LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib

USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
