# Created by: Daniel Knaggs	<knaggsy2000@gmail.com>
# $FreeBSD$

PORTNAME=	danzfs
PORTVERSION=	0.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	knaggsy2000@gmail.com
COMMENT=	Provides a Python API for interacting with ZFS without using libzfs

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)

USE_PYTHON=	distutils
USES=		python tar:xz

WRKSRC=	${WRKDIR}/danzfs

EXAMPLESDIR=	${PREFIX}/share/examples/danzfs

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
