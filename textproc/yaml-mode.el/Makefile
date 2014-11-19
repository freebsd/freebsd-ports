# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	yaml-mode.el
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	Simple major mode to edit YAML file for Emacsen

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	yoshiki
GH_PROJECT=	yaml-mode
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	5eae0c1

USE_EMACS=	yes

MAKE_ENV+=	LISPDIR=${LISPDIR}

LISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

OPTIONS_DEFINE=	DOCS

pre-install:
	${MKDIR} ${LISPDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in Changes README
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
