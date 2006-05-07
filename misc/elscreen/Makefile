# New ports collection makefile for:	elscreen
# Date created:		27 May 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	elscreen
PORTVERSION=	1.4.3
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	GNU screen like utility on Emacsen

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
.if (${EMACS_PORT_NAME} == "emacs21")
DEPPORT_SUFFIX=	
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif

RUN_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}

EMACS_NO_BUILD_DEPENDS=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/elscreen.el ${PREFIX}/${EMACS_SITE_LISPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
