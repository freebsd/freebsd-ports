# Ports collection makefile for:	py-pyxmpp
# Date created:				Mar 04, 2005
# Whom:	      				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	pyxmpp
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	http://jabberstudio.2nw.net/pyxmpp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	A Python XMPP library

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2:install

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-install:
	@${ECHO} "pyxmpp" > ${PYTHON_SITELIBDIR}/pyxmpp.pth

.include <bsd.port.mk>
