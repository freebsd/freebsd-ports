# ex:ts=8
# New ports collection Makefile for:	PyTREX
# Date created:			Mar 16, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trex
PORTVERSION=	0.7.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pytrex
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytrex-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyexpat.so:${PORTSDIR}/textproc/py-expat

USE_PYTHON=	yes

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/pytrex.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pytrex.py ${PREFIX}/bin/pytrex

.include <bsd.port.mk>
