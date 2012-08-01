# New ports collection makefile for:	c-sig
# Date created:				30 May 2004
# Whom:					KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$
#

PORTNAME=	c-sig
PORTVERSION=	3.8
PORTREVISION=	12
CATEGORIES=	mail elisp
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Signature insertion tool for Emacs

USE_EMACS=	yes

NO_WRKSUBDIR=	yes
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile c-sig.el

do-install:
	${MKDIR} ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/c-sig.el* ${LISPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in c-sig-eng.faq c-sig-eng.man c-sig-jp.faq c-sig-jp.man
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
