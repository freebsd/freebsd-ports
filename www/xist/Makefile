# ex:ts=8
# New ports collection makefile for:	XIST
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xist
PORTVERSION= 	1.2.1
CATEGORIES=	www python
MASTER_SITES=	ftp://ftp.livinglogic.de/pub/livinglogic/xist/
DISTNAME=	XIST-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An XML-based extensible HTML generator

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/mx/Tidy/mxTidy/mxTidy.so:${PORTSDIR}/devel/py-mx-experimental

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.for file in doc2txt dtd2xsc xscmake
	@${MV} ${PREFIX}/bin/${file}.py ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
