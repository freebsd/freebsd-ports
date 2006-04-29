# Ports collection makefile for:	py-pyxmpp
# Date created:				Mar 04, 2005
# Whom:	      				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	pyxmpp
PORTVERSION=	1.0.0
CATEGORIES=	net-im python
MASTER_SITES=	http://jabberstudio.2nw.net/pyxmpp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python XMPP library

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_SITELIBDIR}/M2Crypto/__init__.py:${PORTSDIR}/security/py-m2crypto

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s!/usr/bin/python!${PYTHON_CMD}!"

post-install:
	@${ECHO} "pyxmpp" > ${PYTHON_SITELIBDIR}/pyxmpp.pth

.include <bsd.port.mk>
