# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w3af
DISTVERSION=	1.0-rc4
PORTREVISION=	3
CATEGORIES=	security python www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}%20${DISTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Web Application Attack and Audit Framework

LICENSE=	GPLv2

LIB_DEPENDS=	tidy:${PORTSDIR}/www/py-utidy
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/SOAPpy:${PORTSDIR}/net/py-soappy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
		nltk>0:${PORTSDIR}/textproc/nltk \
		${PYTHON_SITELIBDIR}/numpy/__init__.py:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/pyPdf/pdf.py:${PORTSDIR}/print/py-pdf \
		${PYTHON_SITELIBDIR}/scapy/main.py:${PORTSDIR}/net/scapy \
		${PYTHON_SITELIBDIR}/wordnet.py:${PORTSDIR}/textproc/py-wordnet \
		${PYTHON_SITELIBDIR}/yaml/loader.py:${PORTSDIR}/devel/py-yaml
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1PREFIX=	${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/plugins/discovery/oHalberd/
MAN1=		halberd.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		gettext
USE_BZIP2=	yes
USE_PYTHON=	yes

OPTIONS_DEFINE=	GUI

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/pygraphviz/graphviz.py:${PORTSDIR}/graphics/py-graphviz \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

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
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/
	@(cd ${WRKDIR}/build && ${COPYTREE_SHARE} \* ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/)
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_console.sh ${PREFIX}/bin/w3af_console
.if ${PORT_OPTIONS:MGUI}
	@${INSTALL_SCRIPT} ${WRKDIR}/w3af_gui.sh ${PREFIX}/bin/w3af_gui
.endif

.include <bsd.port.mk>
