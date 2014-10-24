# Created by: Jose Jachuf <jjachuf@gmail.com>
# $FreeBSD$

PORTNAME=	PollyReports
PORTVERSION=	1.7.6
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Band-oriented PDF report generation from database query

LICENSE=	BSD2CLAUSE

USES=		python:2
USE_PYTHON=	distutils autoplist

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	REPORTLAB

REPORTLAB_DESC=	Install Reportlab2
REPORTLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2.1:${PORTSDIR}/print/py-reportlab2

.include <bsd.port.mk>
