# Created by: ijliao
# $FreeBSD$
#

PORTNAME=	docutils
PORTVERSION=	0.11
CATEGORIES=	textproc python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Python Documentation Utilities

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_DESC=	Syntax highlighting

BIN_SCRIPTS=	rst2html.py rst2s5.py rst2latex.py rst2xetex.py \
	rst2man.py rst2xml.py rst2pseudoxml.py rstpep2html.py \
	rst2odt.py rst2odt_prepstyles.py

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYGMENTS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

post-install:
.for script in ${BIN_SCRIPTS}
	@cd ${PREFIX}/bin && ${LN} -sf ${script} ${script:C/\.py//}
.endfor

.include <bsd.port.post.mk>
