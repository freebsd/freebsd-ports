# New ports collection makefile for:	py-mxTextTools
# Date created:		12 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-mxTextTools
PORTVERSION= 	1.1.1
CATEGORIES=	textproc python
MASTER_SITES=	http://starship.python.net/~lemburg/
DISTNAME=	mxTextTools-1.1.1

MAINTAINER=	tg@FreeBSD.org

USE_PYTHON=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/TextTools/mxTextTools
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods

TEXTTOOLSDIR=	${PYTHON_SITELIBDIR}/TextTools
DOCDIR=		${PREFIX}/share/doc/py-mxTextTools
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxTextTools

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	@${MKDIR} ${TEXTTOOLSDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/*.py ${TEXTTOOLSDIR}
	@${MKDIR} ${TEXTTOOLSDIR}/Constants
	${INSTALL_DATA} ${WRKDIR}/TextTools/Constants/*.py ${TEXTTOOLSDIR}/Constants
	@${MKDIR} ${TEXTTOOLSDIR}/mxTextTools
.for file in __init__.py mxTextTools.so
	${INSTALL_DATA} ${WRKDIR}/TextTools/mxTextTools/${file} ${TEXTTOOLSDIR}/mxTextTools
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${TEXTTOOLSDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${TEXTTOOLSDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
