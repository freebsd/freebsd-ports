# New ports collection makefile for: py-osd
# Date created:		08 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	osd
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	http://repose.cx/pyosd/ \
		http://damien.kangaweb.com/moving/stuff/pyosd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyosd-${PORTVERSION}

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	A python wrapper for osd, for displaying text on your X display

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

post-extract:
		${MV} ${WRKSRC}/pyosd ${WRKSRC}/osd

.include <bsd.port.mk>
