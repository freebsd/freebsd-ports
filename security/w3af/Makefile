# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w3af
PORTVERSION=	1.6.49
PORTREVISION=	1
CATEGORIES=	security python www

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Web Application Attack and Audit Framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soappy>=0:net/py-soappy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fpconst>0:math/py-fpconst@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk@${FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pdf>0:print/py-pdf@${FLAVOR} \
		scapy>0:net/scapy \
		${PYTHON_PKGNAMEPREFIX}wordnet>0:textproc/py-wordnet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyClamd>=0.2.2:security/py-pyclamd@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygithub>=1.21:devel/py-pygithub@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GitPython>=0.3.2:devel/py-gitpython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybloomfiltermmap>=0.3.11:devel/py-pybloomfiltermmap@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}esmre>=0.3.1:textproc/py-esmre@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phply>=0.9.1:devel/py-phply@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stopit>=1.1.0:devel/py-stopit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.1.1:textproc/py-chardet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tblib>=0.2.0:devel/py-tblib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer>=20140328:textproc/py-pdfminer@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futures>=2.1.5:devel/py-futures@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.3.3:net/py-ndg_httpsclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.3:devel/py-pyasn1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0.3.2:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guess-language>=0.2:textproc/py-guess-language@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cluster>=1.1.1b3:devel/py-cluster@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.4:devel/py-msgpack-python@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ntlm>=1.0.1:net/py-python-ntlm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}halberd>=0.2.4:security/py-halberd@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}darts.util.lru>=0.5:devel/py-darts.util.lru@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.3:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vulndb>=0.0.17:security/py-vulndb@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.1:textproc/py-markdown@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	andresriancho

USES=		gettext python:2.7 shebangfix
USE_PYTHON=	flavors
SHEBANG_FILES=	tools/* w3af_console w3af_gui
NO_BUILD=	yes

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_SUB=	yes

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>0:graphics/py-pygraphviz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtksourceview>=2.10.1:x11-toolkits/py-gtksourceview@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdot>=0.7:x11/py-xdot@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=1.1.8:www/py-webkitgtk@${FLAVOR}

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
