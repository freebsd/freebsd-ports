# New ports collection makefile for:	yaml-mode.el
# Date created:				07 Jun 2007
# Whom:					KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$
#

PORTNAME=	yaml-mode.el
PORTVERSION=	0.0.3
PORTREVISION=	7
CATEGORIES=	textproc elisp
MASTER_SITES=	http://yaml-mode.clouder.jp/attachment/wiki/WikiStart/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME:S/.el$//}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}?format=raw

MAINTAINER=	yasu@utahime.org
COMMENT=	Simple major mode to edit YAML file for Emacsen

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
