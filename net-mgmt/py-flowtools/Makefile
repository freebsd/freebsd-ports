# Ports collection makefile for:	py-flowtools
# Date created:				16 Sep 2004
# Whom:	      				Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	flowtools
PORTVERSION=	0.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	http://mail.net.informatik.tu-muenchen.de/~robin/flowtools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyflowtools-${PORTVERSION}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Python extension module for reading flow-tools' data

BUILD_DEPENDS=	${LOCALBASE}/include/ftlib.h:${PORTSDIR}/net-mgmt/flow-tools

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
