# $FreeBSD$

PORTNAME=	ibus-el
PORTVERSION=	0.3.2
PORTREVISION=	9
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www11.atwiki.jp/s-irie/pub/emacs/ibus/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IBus client for GNU Emacs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	ibus-daemon:textproc/ibus \
		${PYTHON_SITELIBDIR}/Xlib/X.py:x11-toolkits/py-xlib@${PY_FLAVOR}

USES=		emacs python:2.7,run shebangfix

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/ibus.el \
		${EMACS_VERSION_SITE_LISPDIR}/ibus.elc \
		libexec/ibus-el-agent
PORTDOCS=	README
SHEBANG_FILES=	ibus-el-agent

OPTIONS_DEFINE=	DOCS

do-build:
	@(cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ibus.el)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/ibus.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/ibus.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ibus-el-agent \
		${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
