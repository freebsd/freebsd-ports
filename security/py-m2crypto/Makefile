# New ports collection makefile for:	py-m2crypto
# Date created:				27 March 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	m2crypto
PORTVERSION=	0.13.1
CATEGORIES=	security python
MASTER_SITES=	http://sandbox.rulemaker.net/ngps/Dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$//}

PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	Crypto and SSL toolkit for Python

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

PATCHFILES+=	0.13p1.patch

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_ZIP=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" ${WRKSRC}/SWIG/Makefile

.include <bsd.port.mk>
