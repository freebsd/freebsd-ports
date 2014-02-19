# Created by: ijliao
# $FreeBSD$

PORTNAME=	xist
PORTVERSION=	3.25
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	XML-based extensible HTML generator

LICENSE=	MIT

RUN_DEPENDS=	${PYXML} \
		${PYTHON_PKGNAMEPREFIX}ll-core>=1.11.1:${PORTSDIR}/devel/py-ll-core \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.7:${PORTSDIR}/www/py-cssutils

USE_BZIP2=		yes
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
.for conflictswithllcore in __init__ scripts/__init__ ansistyle astyle color \
			    daemon make misc scripts/ucp sisyphus url xml_codec
	${RM} ${WRKSRC}/src/ll/${conflictswithllcore}.py
.endfor

.include <bsd.port.mk>
