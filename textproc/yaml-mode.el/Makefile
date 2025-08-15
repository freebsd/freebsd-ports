PORTNAME=	yaml-mode.el
PORTVERSION=	0.0.16
PORTREVISION=	6
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Simple major mode to edit YAML file for Emacsen
WWW=		https://github.com/yoshiki/yaml-mode

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	yoshiki
GH_PROJECT=	yaml-mode

MAKE_ENV=	LISPDIR=${LISPDIR}

OPTIONS_DEFINE=	DOCS

LISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

pre-install:
	@${MKDIR} ${LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in Changes README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
