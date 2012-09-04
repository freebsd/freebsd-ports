# New ports collection makefile for:	yaml-mode.el
# Date created:				07 Jun 2007
# Whom:					KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$
#

PORTNAME=	yaml-mode.el
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	Simple major mode to edit YAML file for Emacsen

USE_GITHUB=	yes
GH_ACCOUNT=	yoshiki
GH_PROJECT=	yaml-mode
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	c2ac933

USE_EMACS=	yes

MAKE_ENV+=	LISPDIR=${LISPDIR}

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in Changes README
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
