# ex:ts=8
# New ports collection makefile for:	XIST
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xist
PORTVERSION=	2.8
CATEGORIES=	www python
MASTER_SITES=	ftp://ftp.livinglogic.de/pub/livinglogic/xist/
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	An XML-based extensible HTML generator

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/mx/Tidy/mxTidy/mxTidy.so:${PORTSDIR}/devel/py-mx-experimental

USE_PYTHON=	2.4
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes

post-install:
.for file in doc2txt dtd2xsc tld2xsc
	@${MV} ${PREFIX}/bin/${file}.py ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
