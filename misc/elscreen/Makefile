# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elscreen
PORTVERSION=	1.4.6
PORTREVISION=	13
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Emacs utility similar to GNU Screen

RUN_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>0:editors/apel@${EMACS_FLAVOR}

USES=		emacs

NO_ARCH=	yes
NO_BUILD=	YES

PLIST_FILES=	${EMACS_SITE_LISPDIR}/elscreen.el
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/elscreen.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
