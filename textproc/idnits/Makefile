# New ports collection makefile for: idnits
# Date Created:		9 July 2004
# Whom:			fenner@FreeBSD.Org
#
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	2.12.04
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/ \
		http://sunpoet.net/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Looks for problems in internet draft formatting

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	YES

PLIST_FILES=	bin/idnits

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
