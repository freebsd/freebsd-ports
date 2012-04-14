# New ports collection makefile for:	py-viper
# Date created:				13 April 2012
# Whom:					Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	viper
PORTVERSION=	1.0.0
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/fenics-${PORTNAME}/1.0.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimalistic scientific plotter and visualization module

LICENSE=	LGPL3

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	viper

FETCH_ARGS=	-F

MAN1=		viper.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|data_files=\[(join("share", "man", "man1"),|data_files=\[(join("man", "man1"),|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
