# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	pyxmpp
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	net-im python
MASTER_SITES=	GHC
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python XMPP library

LICENSE=	LGPL21 # only
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.18.2:security/py-m2crypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libxml2>0:textproc/py-libxml2@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	Jajcus

USES=		python:2.7 shebangfix
SHEBANG_FILES=	auxtools/*.py examples/*.py tests/*.py utils/*.py
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e \
		"/include_dirs =/s|\[.*|['${LOCALBASE}/include/libxml2','${LOCALBASE}/include']| ; \
		 /library_dirs =/s|\[.*|['${LOCALBASE}/lib']|" ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyxmpp/_xmlextra.so

.include <bsd.port.mk>
