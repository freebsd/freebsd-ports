# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	itstool
PORTVERSION=	2.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Make XML documents translatable through po files

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_BZIP2=	yes
USE_PYTHON_RUN=	2
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|g' \
		${WRKSRC}/itstool.in

.include <bsd.port.mk>
