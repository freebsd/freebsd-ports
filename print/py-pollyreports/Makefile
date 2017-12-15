# Created by: Jose Jachuf <jjachuf@gmail.com>
# $FreeBSD$

PORTNAME=	PollyReports
PORTVERSION=	1.7.7
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Band-oriented PDF report generation from database query

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	REPORTLAB

REPORTLAB_DESC=	Install Reportlab
REPORTLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>=3.0:print/py-reportlab@${FLAVOR}

.include <bsd.port.mk>
