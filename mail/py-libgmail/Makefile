# Ports collection makefile for:	libgmail
# Date created:				Sep 27, 2005
# Whom:					Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libgmail
DISTVERSION=	0.1.10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Library to provide access to Gmail via Python

BUILD_DEPENDS=	py*-mechanize>=0:${PORTSDIR}/www/py-mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/lgconstants.py \
		%%PYTHON_SITELIBDIR%%/lgconstants.pyc \
		%%PYTHON_SITELIBDIR%%/lgconstants.pyo \
		%%PYTHON_SITELIBDIR%%/libgmail.py \
		%%PYTHON_SITELIBDIR%%/libgmail.pyc \
		%%PYTHON_SITELIBDIR%%/libgmail.pyo

.include <bsd.port.mk>
