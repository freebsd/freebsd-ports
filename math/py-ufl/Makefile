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

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	UFL

MAN1=		form2ufl.1 \
		ufl-analyse.1 \
		ufl-convert.1 \
		ufl-version.1 \
		ufl2py.1
MANCOMPRESSED=	yes

MMVERSION=	1.2

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|\[(pjoin("share", "man", "man1"),|\[(pjoin("man", "man1"),|' \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
