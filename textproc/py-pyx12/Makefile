# Created by: john@zoner.org
# $FreeBSD$

PORTNAME=	pyx12
PORTVERSION=	1.5.0
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyx12-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validate and convert HIPAA X12 documents

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

MAN1=	x12valid.1 x12norm.1 x12xml.1 x12html.1 xmlx12.1
MAN5=	pyx12.conf.xml.5
SUB_FILES=	pkg-deinstall

NO_STAGE=	yes
post-install:
	${PYTHON_CMD} ${WRKSRC}/bin/x12_build_pkl.py ${PREFIX}/share/pyx12/map/
	cd ${WRKSRC}/bin && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/bin && ${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
