# $FreeBSD$

PORTNAME=	ufl
PORTVERSION=	${MMVERSION}0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${MMVERSION}.0

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unified Form Language for finite element discretizations

LICENSE=	LGPL3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils autoplist

MMVERSION=	1.2

post-patch:
	@${REINPLACE_CMD} -e 's|\[(pjoin("share", "man", "man1"),|\[(pjoin("man", "man1"),|' \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
