# Created by: ijliao
# $FreeBSD$

PORTNAME=	docutils
PORTVERSION=	0.12
CATEGORIES=	textproc python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Python Documentation Utilities

USES=	python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_DESC=	Syntax highlighting

BIN_SCRIPTS=	rst2html.py rst2s5.py rst2latex.py rst2xetex.py \
	rst2man.py rst2xml.py rst2pseudoxml.py rstpep2html.py \
	rst2odt.py rst2odt_prepstyles.py

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYGMENTS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments
.endif

post-install:
.for script in ${BIN_SCRIPTS}
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf ${script} ${script:C/\.py//}
.endfor

.include <bsd.port.mk>
