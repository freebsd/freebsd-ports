# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/itstool/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	itstool
PORTVERSION=	2.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/
PKGNAMESUFFIX=	22

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Make XML documents translatable through po files

LICENSE=	GPLv3

DEPRECATED=	Uses deprecated version of python, use textproc/itstool instead
EXPIRATION_DATE=2020-04-14

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${PY_FLAVOR}

USES=		python:2.7 tar:bzip2

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	itstool

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|g' \
		${WRKSRC}/itstool.in

.include <bsd.port.mk>
