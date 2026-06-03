PORTNAME=	yaml-mode.el
PORTVERSION=	0.0.16
PORTREVISION=	7
CATEGORIES=	textproc elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple major mode to edit YAML file for Emacsen
WWW=		https://github.com/yoshiki/yaml-mode

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	yoshiki
GH_PROJECT=	yaml-mode

CONFLICTS_INSTALL=	yaml-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

LISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

do-install:
	@${MKDIR} ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in Changes README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
