# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w3af
DISTVERSION=	1.0-rc4
PORTREVISION=	6
CATEGORIES=	security python www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web Application Attack and Audit Framework

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}soappy>=0:net/py-soappy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}fpconst>0:math/py-fpconst \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pdf>0:print/py-pdf \
		scapy>0:net/scapy \
		${PYTHON_PKGNAMEPREFIX}wordnet>0:textproc/py-wordnet \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		gettext python tar:bzip2

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	yes

GUI_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz
GUI_USE=	GNOME=pygtk2

.include <bsd.port.options.mk>

do-patch:
.for f in SOAPpy fpconst-0.7.2 nltk nltk_contrib pyPdf scapy yaml
	@${RM} -rf ${WRKSRC}/extlib/${f}
.endfor
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
			-E "s!/usr/bin/python2?!${PYTHON_CMD}!"
do-build:
	@${MKDIR} ${WRKDIR}/build
	@${MKDIR} ${WRKSRC}/build/extlib
	@${CP} ${WRKSRC}/w3af_console ${WRKDIR}/build/w3af_console.py
.if ${PORT_OPTIONS:MGUI}
	@${CP} ${WRKSRC}/w3af_gui ${WRKDIR}/build/w3af_gui.py
.endif
.for f in core locales plugins profiles readme scripts tools
	@${MKDIR} ${WRKDIR}/build/${f}
	@(cd ${WRKSRC}/${f}/ && ${COPYTREE_SHARE} \* ${WRKDIR}/build/${f})
.endfor
.for ext in cluster gtkcodebuffer ntlm socksipy xdot
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
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	@(cd ${WRKDIR}/build && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME})
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_console.sh \
		${STAGEDIR}${PREFIX}/bin/w3af_console
.if ${PORT_OPTIONS:MGUI}
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_gui.sh \
		${STAGEDIR}${PREFIX}/bin/w3af_gui
.endif

.include <bsd.port.mk>
