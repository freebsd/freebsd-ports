PORTNAME=	mu4e-maildirs
PORTVERSION=	0.8.20201028
PORTREVISION=	19
CATEGORIES=	mail
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Maildirs extension for Mu4e
WWW=		https://github.com/agpchil/mu4e-maildirs-extension

LICENSE=	GPLv3

DEPRECATED=	Upstream discourages using this software and recommends feature now integrated into mail/mu
EXPIRATION_DATE=	2025-11-30
BROKEN=		does not build with recent version of mail/mu: Cannot open load file: No such file or directory, mu4e-config

BUILD_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>0:devel/dash.el@${EMACS_FLAVOR} \
		mu>0:mail/mu
RUN_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>0:devel/dash.el@${EMACS_FLAVOR} \
		mu>0:mail/mu

USES=		emacs
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-extension
GH_ACCOUNT=	agpchil
GH_TAGNAME=	1167bc6

NO_ARCH=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/mu4e/mu4e-maildirs-extension.elc \
		${EMACS_SITE_LISPDIR}/mu4e/mu4e-maildirs-extension.el.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${EMACS_CMD} --batch \
	    --eval "(provide 'mu4e)" \
	    --eval "(defvar mu4e~main-buffer-name \"tests\")" \
	    --eval "(defvar mu4e-mu-binary \"mu\")" \
	    --eval "(require 'cl)" \
	    -l dash.el \
	    -l mu4e-maildirs-extension.el \
	    --eval "(byte-compile-file \"mu4e-maildirs-extension.el\")" && \
	    ${GZIP_CMD} mu4e-maildirs-extension.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e && \
	    cd ${WRKSRC} && ${INSTALL_DATA} \
	    mu4e-maildirs-extension.elc \
	    mu4e-maildirs-extension.el.gz \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	    cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
