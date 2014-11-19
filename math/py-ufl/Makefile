# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ufl
PORTVERSION=	${MMVERSION}0
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/${MMVERSION}.0/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${MMVERSION}.0

MAINTAINER=	jwbacon@tds.net
COMMENT=	Unified Form Language for finite element discretizations

LICENSE=	LGPL3

USES=		python:2
USE_PYTHON=	distutils autoplist

MMVERSION=	1.2

post-patch:
	@${REINPLACE_CMD} -e 's|\[(pjoin("share", "man", "man1"),|\[(pjoin("man", "man1"),|' \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
