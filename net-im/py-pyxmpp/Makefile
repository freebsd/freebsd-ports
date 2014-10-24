# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	pyxmpp
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	net-im python
MASTER_SITES=	GHC
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python XMPP library

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.18.2:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}libxml2>0:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	Jajcus

USES=		python shebangfix
SHEBANG_FILES=	auxtools/*.py examples/*.py tests/*.py utils/*.py
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e \
		"/include_dirs =/s|\[.*|['${LOCALBASE}/include/libxml2','${LOCALBASE}/include']| ; \
		 /library_dirs =/s|\[.*|['${LOCALBASE}/lib']|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
