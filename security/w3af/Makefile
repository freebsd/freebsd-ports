# New ports collection makefile for:	w3af
# Date created:				Wed Aug 29 21:44:33 CEST 2007
# Whom:					Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	w3af
PORTVERSION=	0.1.20070610
CATEGORIES=	security python www
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-10Jun2007

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Web Application Attack and Audit Framework

LIB_DEPENDS=	tidy-0.99.0:$(PORTSDIR)/www/py-utidy
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/SOAPpy:${PORTSDIR}/net/py-soappy \
		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
		${PYTHON_SITELIBDIR}/wordnet.py:${PORTSDIR}/textproc/py-wordnet
#		${PYTHON_SITELIBDIR}/google.py:${PORTSDIR}/net/py-google \
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_PYTHON=	2.5+

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
			-E "s!/usr/bin/python2?!${PYTHON_CMD}!"

do-build:
	${MKDIR} ${WRKDIR}/build
	${CP} -R ${WRKSRC}/w3af ${WRKDIR}/build/w3af.py
.for f in core plugins scripts tools webroot
	${CP} -R ${WRKSRC}/${f} ${WRKDIR}/build/
.endfor
# The next 5 lines are temporary, until dependency on py-google port works
	${MKDIR} ${WRKDIR}/build/extlib
	${RM} -rf ${WRKSRC}/extlib/pygoogle/build
	${RM} -rf ${WRKSRC}/extlib/pygoogle/doc
	${CP} -R ${WRKSRC}/extlib/pygoogle ${WRKDIR}/build/extlib
	${CP} ${WRKSRC}/extlib/__init__.py ${WRKDIR}/build/extlib
# ----
	${PYTHON_CMD} -m compileall ${WRKDIR}/build
	${PYTHON_CMD} -O -m compileall ${WRKDIR}/build
	${SED} -e 's:%%PATH%%:${PYTHON_SITELIBDIR}/${PORTNAME}/:' \
		-e 's:%%PYTHON_CMD%%:${PYTHON_CMD}:' \
		< ${FILESDIR}/w3af.sh > ${WRKDIR}/w3af.sh

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}/
	${CP} -R ${WRKDIR}/build/* ${PYTHON_SITELIBDIR}/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKDIR}/w3af.sh ${LOCALBASE}/bin/w3af

.include <bsd.port.mk>
