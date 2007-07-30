# Ports collection makefile for:	py-flowtools
# Date created:				16 Sep 2004
# Whom:	      				Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	flowtools
PORTVERSION=	0.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	http://www.icir.org/robin/flowtools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyflowtools-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python extension module for reading flow-tools' data

BUILD_DEPENDS=	${LOCALBASE}/include/ftlib.h:${PORTSDIR}/net-mgmt/flow-tools

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/flowtools.so

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyflowtools

.include <bsd.port.mk>
