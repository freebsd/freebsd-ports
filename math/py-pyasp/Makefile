# $FreeBSD$

PORTNAME=	pyasp
DISTVERSION=	1.4.4
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenience wrapper for the ASP tools gringo and clasp

LICENSE=	GPLv3

RUN_DEPENDS=	clasp:math/clasp \
		gringo:math/gringo

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e " \
		s|'bin/'|'${PREFIX}/bin/'| ; \
		s|'gringo4'|'gringo'| ; \
		s|access_packaged_file(REL_DIR_BIN + bin_name)|REL_DIR_BIN + bin_name|" \
		${WRKSRC}/pyasp/constant.py

.include <bsd.port.mk>
