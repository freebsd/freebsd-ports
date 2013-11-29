# $FreeBSD$

PORTNAME=	pybeanstalk
PORTVERSION=	0.11.1
CATEGORIES=	net python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure python client library for beanstalkd queue

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALL_EGGINFO=yes
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

WRKSRC=	${WRKDIR}/${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
