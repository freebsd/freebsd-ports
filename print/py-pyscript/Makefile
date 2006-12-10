# New ports collection makefile for:	py-script
# Date created:		2006-04-28
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	pyscript
PORTVERSION=	0.6.1
CATEGORIES=	print graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module for producing high quality PostScript graphics

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DATADIR=	${PYTHON_SITELIBDIR}/${PORTNAME}

PYSCRIPT_EXAMPLES=	doc/examples/*.py
PYSCRIPT_MANUAL=	doc/manual/pyscript.pdf

.if defined(WITHOUT_EXAMPLES)
PORTEXAMPLES=	"@comment "
.else
PORTEXAMPLES=	""
.endif
PLIST_SUB+=	PORTEXAMPLES=${PORTEXAMPLES}

post-install:

.if !defined(WITHOUT_EXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PYSCRIPT_EXAMPLES} ${EXAMPLESDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PYSCRIPT_MANUAL} ${DOCSDIR}
.endif

.include <bsd.port.mk>
