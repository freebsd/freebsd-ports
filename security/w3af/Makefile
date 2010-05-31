# New ports collection makefile for:	w3af
# Date created:				Wed Aug 29 21:44:33 CEST 2007
# Whom:					Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	w3af
DISTVERSION=	1.0-rc2
PORTREVISION=	1
CATEGORIES=	security python www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}%20${DISTVERSION}%20%5bshorty%5d
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Web Application Attack and Audit Framework

LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/py-utidy
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/SOAPpy:${PORTSDIR}/net/py-soappy \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
		${PYTHON_SITELIBDIR}/json.py:${PORTSDIR}/devel/py-json-py \
		${PYTHON_SITELIBDIR}/nltk/util.py:${PORTSDIR}/textproc/nltk \
		${PYTHON_SITELIBDIR}/pyPdf/pdf.py:${PORTSDIR}/print/py-pdf \
		${PYTHON_SITELIBDIR}/scapy/main.py:${PORTSDIR}/net/scapy \
		${PYTHON_SITELIBDIR}/wordnet.py:${PORTSDIR}/textproc/py-wordnet \
		${PYTHON_SITELIBDIR}/yaml/loader.py:${PORTSDIR}/devel/py-yaml
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_PYTHON=	2.5+

OPTIONS=	GUI "Support for graphical user interface" off

.include <bsd.port.options.mk>

.if defined(WITH_GUI)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/pygraphviz/graphviz.py:${PORTSDIR}/graphics/py-graphviz \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

do-patch:
.for f in SOAPpy fpconst-0.7.2 jsonpy nltk nltk_contrib pyPdf scapy yaml
	@${RM} -rf ${WRKSRC}/extlib/${f}
.endfor
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
			-E "s!/usr/bin/python2?!${PYTHON_CMD}!"

do-build:
	@${MKDIR} ${WRKDIR}/build
	@${MKDIR} ${WRKSRC}/build/extlib
	@${CP} ${WRKSRC}/w3af_console ${WRKDIR}/build/w3af_console.py
.if defined(WITH_GUI)
	@${CP} ${WRKSRC}/w3af_gui ${WRKDIR}/build/w3af_gui.py
.endif
.for f in core locales plugins profiles readme scripts tools
	@${MKDIR} ${WRKDIR}/build/${f}
	@(cd ${WRKSRC}/${f}/ && ${COPYTREE_SHARE} \* ${WRKDIR}/build/${f})
.endfor
.for ext in cluster pygoogle socksipy xdot
	@${MKDIR} ${WRKDIR}/build/extlib/${ext}
	@(cd ${WRKSRC}/extlib/${ext}/ && ${COPYTREE_SHARE} \* ${WRKDIR}/build/extlib/${ext})
.endfor
	@${CP} ${WRKSRC}/extlib/__init__.py ${WRKDIR}/build/extlib/
	@${PYTHON_CMD} -m compileall ${WRKDIR}/build
	@${PYTHON_CMD} -O -m compileall ${WRKDIR}/build
.for f in w3af_console w3af_gui
	@${SED} -e 's:%%PATH%%:${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/:' \
		-e 's:%%PYTHON_CMD%%:${PYTHON_CMD}:' \
		< ${FILESDIR}/${f}.sh > ${WRKDIR}/${f}.sh
.endfor

do-install:
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/
	@(cd ${WRKDIR}/build && ${COPYTREE_SHARE} \* ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/)
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_console.sh ${PREFIX}/bin/w3af_console
.if defined(WITH_GUI)
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_gui.sh ${PREFIX}/bin/w3af_gui
.endif

.include <bsd.port.mk>
