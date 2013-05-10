# New ports collection makefile for:	danzfs
# Date created:		26 May 2012
# Whom:			Daniel Knaggs	<knaggsy2000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	danzfs
PORTVERSION=	0.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	knaggsy2000@gmail.com
COMMENT=	Provides a Python API for interacting with ZFS without using libzfs

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_XZ=	yes

WRKSRC=	${WRKDIR}/danzfs

EXAMPLESDIR=	${PREFIX}/share/examples/danzfs

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include <bsd.port.mk>
