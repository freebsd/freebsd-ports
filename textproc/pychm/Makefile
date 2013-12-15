# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	pychm
PORTVERSION=	0.8.4
CATEGORIES=	textproc python
MASTER_SITES=	SF/gnochm/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bindings for CHMLIB library

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

.include <bsd.port.post.mk>
