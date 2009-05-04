# Ports collection makefile for:	py-pyxmpp
# Date created:				Mar 04, 2005
# Whom:	      				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	pyxmpp
PORTVERSION=	1.0.1
CATEGORIES=	net-im python
MASTER_SITES=	http://pyxmpp.jajcus.net/downloads/ \
		CENKES http://jabberstudio.2nw.net/pyxmpp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Python XMPP library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.18.2:${PORTSDIR}/security/py-m2crypto
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s!/usr/bin/python!${PYTHON_CMD}!"
	@${REINPLACE_CMD} -e '/include_dirs =/s|]|,"${LOCALBASE}/include"]|' \
		-e '/library_dirs =/s|]|"${LOCALBASE}/lib"]|' ${WRKSRC}/setup.py

post-install:
	@${ECHO} "pyxmpp" > ${PYTHON_SITELIBDIR}/pyxmpp.pth

.include <bsd.port.mk>
