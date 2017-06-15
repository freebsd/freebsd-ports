# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w3af
PORTVERSION=	1.6.49
CATEGORIES=	security python www

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Web Application Attack and Audit Framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1:devel/py-lxml \
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
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyClamd>=0.2.2:security/py-pyclamd \
		${PYTHON_PKGNAMEPREFIX}pygithub>=1.21:devel/py-pygithub \
		${PYTHON_PKGNAMEPREFIX}GitPython>=0.3.2:devel/py-gitpython \
		${PYTHON_PKGNAMEPREFIX}pybloom>=0.3.11:math/py-pybloom \
		${PYTHON_PKGNAMEPREFIX}esmre>=0.3.1:textproc/py-esmre \
		${PYTHON_PKGNAMEPREFIX}phply>=0.9.1:devel/py-phply \
		${PYTHON_PKGNAMEPREFIX}stopit>=1.1.0:devel/py-stopit \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.1.1:textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}tblib>=0.2.0:devel/py-tblib \
		${PYTHON_PKGNAMEPREFIX}pdfminer=20140328:textproc/py-pdfminer \
		${PYTHON_PKGNAMEPREFIX}futures>=2.1.5:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.3.3:net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.3:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}lxml>=0.3.2:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}guess-language>=0.2:textproc/py-guess-language \
		${PYTHON_PKGNAMEPREFIX}cluster>=1.1.1b3:devel/py-cluster \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.4:devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}python-ntlm>=1.0.1:net/py-python-ntlm \
		${PYTHON_PKGNAMEPREFIX}halberd>=0.2.4:security/py-halberd \
		${PYTHON_PKGNAMEPREFIX}darts.util.lru>=0.5:devel/py-darts.util.lru \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.3:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}vulndb>=0.0.17:security/py-vulndb \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.1:textproc/py-markdown

USE_GITHUB=	yes
GH_ACCOUNT=	andresriancho

USES=		gettext python shebangfix
SHEBANG_FILES=	tools/*
NO_BUILD=	yes

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_SUB=	yes

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>0:graphics/py-pygraphviz \
		${PYTHON_PKGNAMEPREFIX}gtksourceview>=2.10.1:x11-toolkits/py-gtksourceview \
		${PYTHON_PKGNAMEPREFIX}xdot>=0.7:x11/py-xdot \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=1.1.8:www/py-webkitgtk

GUI_USE=	GNOME=pygtk2

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	@(cd ${WRKSRC}/w3af && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME})
	${INSTALL_SCRIPT} ${WRKSRC}/w3af_console \
		${STAGEDIR}${PREFIX}/bin/w3af_console
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in base64decode base64encode gencc md5hash sha1hash urldecode urlencode
	 ${INSTALL_SCRIPT} ${WRKSRC}/tools/${f} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${f}
.endfor
.for f in extras profiles scripts
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/${f}
	@(cd ${WRKSRC}/${f}/ && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/${f})
.endfor

do-install-GUI-on:
	${INSTALL_SCRIPT} ${WRKSRC}/w3af_gui \
		${STAGEDIR}${PREFIX}/bin/w3af_gui

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in CHANGELOG CONTRIBUTORS INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
