# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-subfile
PORTVERSION=	0.5.3
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Find subfiles in any binary stream

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:${PORTSDIR}/devel/hachoir-parser \
		${PYTHON_SITELIBDIR}/hachoir_regex/__init__.py:${PORTSDIR}/devel/hachoir-regex

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
