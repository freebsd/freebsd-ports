# $FreeBSD$

PORTNAME=	viper
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/fenics-${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimalistic scientific plotter and visualization module

LICENSE=	LGPL3

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|data_files=\[(join("share", "man", "man1"),|data_files=\[(join("man", "man1"),|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
