# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	1.8.1
CATEGORIES=	math python
MASTER_SITES=	http://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex network

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYTHON_PY3K_PLIST_HACK=yes
PYSETUP=	setup_egg.py
PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
