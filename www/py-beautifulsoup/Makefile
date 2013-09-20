# Created by: Mike Meyer
# $FreeBSD$

PORTNAME=	beautifulsoup
PORTVERSION=	4.3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	beautifulsoup4-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	HTML/XML Parser for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	beautifulsoup4

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
