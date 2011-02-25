# New ports collection makefile for: idnits
# Date Created:		9 July 2004
# Whom:			fenner@FreeBSD.Org
#
# $FreeBSD$
#

PORTNAME=	idnits
PORTVERSION=	2.12.07
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/ \
		LOCAL/sunpoet
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Looks for problems in internet draft formatting

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '1 s|^#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
