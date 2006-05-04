# New ports collection makefile for:	kedpm
# Date created:				25 April 2006
# Whom:					Tim Welch <ports@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	kedpm
PORTVERSION=	0.4.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kedpm

MAINTAINER=	ports@thepentagon.org
COMMENT=	A simple application for managing personal data

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_GNOME=	pygtk2
USE_PYTHON=	2.1+
USE_PYDISTUTILS=	YES

.include <bsd.port.mk>
