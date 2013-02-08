# Created by: Jose Jachuf <jjachuf@gmail.com>
# $FreeBSD$

PORTNAME=	PollyReports
PORTVERSION=	1.7.2
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Band-oriented PDF report generation from database query

LICENSE=	BSD

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/PollyReports.py \
		%%PYTHON_SITELIBDIR%%/PollyReports.pyc \
		%%PYTHON_SITELIBDIR%%/PollyReports.pyo

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	REPORTLAB
REPORTLAB_DESC=	Install Reportlab2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREPORTLAB}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2.1:${PORTSDIR}/print/py-reportlab2
.endif

.include <bsd.port.mk>
