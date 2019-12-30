# Created by: ijliao
# $FreeBSD$

PORTNAME=	docutils
PORTVERSION=	0.15.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python Documentation Utilities

LICENSE=	BSD2CLAUSE GPLv3+ PD PSFL
LICENSE_COMB=	multi

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_DESC=	Syntax highlighting
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}

SCRIPTS=	rst2html rst2latex rst2man rst2odt rst2odt_prepstyles \
		rst2pseudoxml rst2s5 rst2xetex rst2xml rstpep2html

post-install:
.for script in ${SCRIPTS}
	${LN} -s ${script}.py-${PYTHON_VER} ${STAGEDIR}${PREFIX}/bin/${script}
.endfor

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test/alltests.py --verbose

.include <bsd.port.mk>
