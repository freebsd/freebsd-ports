# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elscreen
PORTVERSION=	1.4.6
PORTREVISION=	10
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	GNU screen like utility on Emacsen

RUN_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:editors/apel

USE_EMACS=	yes

EMACS_NO_BUILD_DEPENDS=	YES
NO_BUILD=	YES

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/elscreen.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
