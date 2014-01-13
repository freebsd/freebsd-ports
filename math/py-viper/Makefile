# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	viper
PORTVERSION=	${MMVERSION}.1
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/fenics-${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Minimalistic scientific plotter and visualization module

LICENSE=	LGPL3

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	viper

MAN1=		viper.1
MANCOMPRESSED=	yes

MMVERSION=	1.0

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|data_files=\[(join("share", "man", "man1"),|data_files=\[(join("man", "man1"),|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
