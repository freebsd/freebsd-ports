# $FreeBSD$

PORTNAME=	mu4e-maildirs
PORTVERSION=	0.8.20160126
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Maildirs extension for Mu4e

LICENSE=	GPLv3

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/dash.el:devel/dash.el \
		${LOCALBASE}/${EMACS_SITE_LISPDIR}/mu4e/mu4e.elc:mail/mu4e

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-extension
GH_ACCOUNT=	agpchil
GH_TAGNAME=	f759dff
USE_EMACS=	yes
NO_CONFIGURE=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/mu4e/mu4e-maildirs-extension.elc \
		${EMACS_SITE_LISPDIR}/mu4e/mu4e-maildirs-extension.el.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${EMACS_CMD} --batch \
	    -f batch-byte-compile mu4e-maildirs-extension.el && \
	    ${GZIP_CMD} mu4e-maildirs-extension.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e
	cd ${WRKSRC} && ${INSTALL_DATA} \
	    mu4e-maildirs-extension.elc \
	    mu4e-maildirs-extension.el.gz \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
