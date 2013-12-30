# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	pyxmpp
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://cloud.github.com/downloads/Jajcus/pyxmpp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python XMPP library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.18.2:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s|/usr/bin/python|${PYTHON_CMD}|"
	@${REINPLACE_CMD} -e \
		"/include_dirs =/s|\[.*|['${LOCALBASE}/include/libxml2','${LOCALBASE}/include']| ; \
		 /library_dirs =/s|\[.*|['${LOCALBASE}/lib']|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
