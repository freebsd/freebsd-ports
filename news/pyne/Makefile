# ex:ts=8
# New ports collection makefile for:	pyne
# Date created:			Dec 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyne
PORTVERSION=	0.6.7
CATEGORIES=	news python
MASTER_SITES=	http://www.yikesstation.freeserve.co.uk/pyne/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk

USE_PYTHON=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,^PREFIX,#PREFIX,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
