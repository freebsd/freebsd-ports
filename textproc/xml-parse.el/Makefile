# New ports collection makefile for:	xml-parse.el
# Date created:				March 09 2005
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	xml-parse.el
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dryice.name/computer/FreeBSD/distfiles/ \
		http://sacha.free.net.ph/notebook/emacs/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	dryice@dryice.name
COMMENT=	Code to efficiently read/write XML data with Elisp

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
