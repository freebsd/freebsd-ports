# ex:ts=8
# New ports collection makefile for:	py-fckhsum
# Date created:			Jul 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fchksum
PORTVERSION=	1.6.1
CATEGORIES=	security python
MASTER_SITES=	http://www.dakotacom.net/~donut/programs/fchksum/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module to find the checksum of files

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/fchksum.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
