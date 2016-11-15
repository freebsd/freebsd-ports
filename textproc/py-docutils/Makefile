# Created by: ijliao
# $FreeBSD$

PORTNAME=	docutils
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Python Documentation Utilities

LICENSE=	BSD2CLAUSE GPLv3+ PD PSFL
LICENSE_COMB=	multi

USES=	python
USE_PYTHON=	distutils concurrent autoplist

OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments
PYGMENTS_DESC=	Syntax highlighting

BIN_SCRIPTS=	rst2html.py rst2s5.py rst2latex.py rst2xetex.py \
	rst2man.py rst2xml.py rst2pseudoxml.py rstpep2html.py \
	rst2odt.py rst2odt_prepstyles.py

post-install:
.for script in ${BIN_SCRIPTS}
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf ${script} ${script:C/\.py//}
.endfor

.include <bsd.port.mk>
