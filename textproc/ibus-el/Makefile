# $FreeBSD$

PORTNAME=	ibus-el
PORTVERSION=	0.3.2
#PORTREVISION=	0
PORTREVISION=	5
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www11.atwiki.jp/s-irie/pub/emacs/ibus/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IBus client for GNU Emacs

RUN_DEPENDS=	ibus-daemon:textproc/ibus \
		${PYTHON_SITELIBDIR}/Xlib/X.py:x11-toolkits/py-xlib

USES=		python:2.7,run
USE_EMACS=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/COPYING

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/ibus.el \
		${EMACS_VERSION_SITE_LISPDIR}/ibus.elc \
		libexec/ibus-el-agent
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ibus.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	@${INSTALL_DATA} ${WRKSRC}/ibus.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	@${INSTALL_DATA} ${WRKSRC}/ibus.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ibus-el-agent \
		${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
