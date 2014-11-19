# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	flowtools
PORTVERSION=	0.3.4.1
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyflowtools-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python extension module for reading flow-tools' data

BUILD_DEPENDS=	${LOCALBASE}/include/ftlib.h:${PORTSDIR}/net-mgmt/flow-tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
USES=		python
USE_PYTHON=	distutils autoplist

PROJECTHOST=	py${PORTNAME}

.include <bsd.port.mk>
