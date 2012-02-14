# New ports collection makefile for:   itstool
# Date Created:			17 Sept 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	itstool
PORTVERSION=	1.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Make XML documents translatable through po files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

MAN1=		itstool.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/itstool.in

.include <bsd.port.mk>
