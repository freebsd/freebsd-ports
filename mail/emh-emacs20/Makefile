# New ports collection makefile for:	emh
# Date Created:		12 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	emh
PORTVERSION=	1.10.1
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/emh/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS+=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

MIMEUI_PRODUCT?=	semi
MIMEUI_BRANCH?=		1.13
MIMEUI_PORT_NAME?=	${MIMEUI_PRODUCT}${MIMEUI_BRANCH:S/.//}-${EMACS_PORT_NAME}
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_BRANCH}.FreeBSD-packages

EMACS_PORT_NAME?=	emacs20

ALL_TARGET?=	elc
EMH_LISPDIR?=	share/emacs/site-lisp/semi
XEMACS_ONLY?=	"@comment "

PLIST_SUB=	XEMACS_ONLY=${XEMACS_ONLY} \
		EMH_LISPDIR=${EMH_LISPDIR}

.include <bsd.port.mk>
