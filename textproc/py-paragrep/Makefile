# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paragrep
PORTVERSION=	3.1.1
CATEGORIES=	textproc python
MASTER_SITES=	http://github.com/bmc/paragrep/zipball/release-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Paragraph Grep Utility

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grizzled>=0.8.1:${PORTSDIR}/devel/py-grizzled
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=	${WRKDIR}/bmc-${PORTNAME}-e7d5553
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=yes

post-patch:
	@${REINPLACE_CMD} -e "s|'man'|'man/man1'|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
